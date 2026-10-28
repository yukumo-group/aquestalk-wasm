import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import java.io.*;
import java.util.*;

public class DumpData extends GhidraScript {
    public void run() throws Exception {
        String outPath = getScriptArgs()[0];
        PrintWriter pw = new PrintWriter(new File(outPath));
        Listing lst = currentProgram.getListing();
        // iterate all defined data
        DataIterator it = lst.getDefinedData(true);
        while (it.hasNext()) {
            Data d = it.next();
            if (d == null) continue;
            String name = d.getPrimarySymbol() != null ? d.getPrimarySymbol().getName() : "";
            if (!(name.startsWith("DAT_") || name.startsWith("PTR_") || name.startsWith("UNK") || name.startsWith("_DAT"))) continue;
            DataType dt = d.getDataType();
            pw.println(d.getAddress() + "\t" + name + "\t" + dt.getName() + "\t" + d.getLength());
        }
        pw.close();
    }
}
