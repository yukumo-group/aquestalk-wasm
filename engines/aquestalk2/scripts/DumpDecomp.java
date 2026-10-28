import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import java.io.*;
import java.util.*;

public class DumpDecomp extends GhidraScript {
    public void run() throws Exception {
        String outDir = getScriptArgs().length > 0 ? getScriptArgs()[0] : "/tmp/decomp";
        File dir = new File(outDir);
        dir.mkdirs();
        DecompInterface dec = new DecompInterface();
        dec.toggleCCode(true);
        dec.toggleSyntaxTree(true);
        dec.setSimplificationStyle("decompile");
        if (!dec.openProgram(currentProgram)) {
            println("decompiler open failed: " + dec.getLastMessage());
        }
        FunctionManager fm = currentProgram.getFunctionManager();
        PrintWriter list = new PrintWriter(new File(dir, "functions.tsv"));
        PrintWriter all = new PrintWriter(new File(dir, "all.c"));
        int n = 0;
        for (Function f : fm.getFunctions(true)) {
            n++;
            long size = f.getBody().getNumAddresses();
            list.println(f.getEntryPoint() + "\t" + size + "\t" + f.getName() + "\t" + f.getCallingConventionName());
            DecompileResults res = dec.decompileFunction(f, 90, monitor);
            File out = new File(dir, String.format("FUN_%s.c", f.getEntryPoint()));
            PrintWriter pw = new PrintWriter(out);
            pw.println("// " + f.getName() + " @ " + f.getEntryPoint() + " size=" + size);
            if (res.decompileCompleted()) {
                String c = res.getDecompiledFunction().getC();
                pw.println(c);
                all.println("//===== " + f.getName() + " @ " + f.getEntryPoint() + " size=" + size + " =====");
                all.println(c);
            } else {
                pw.println("// DECOMP FAILED: " + res.getErrorMessage());
                all.println("// DECOMP FAILED: " + f.getName() + " " + res.getErrorMessage());
            }
            pw.close();
        }
        list.close();
        all.close();
        println("FUNCTIONS=" + n);
    }
}
