import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;

public class DumpRange extends GhidraScript {
    public void run() throws Exception {
        long lo = Long.parseLong(getScriptArgs()[0], 16);
        long hi = Long.parseLong(getScriptArgs()[1], 16);
        Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(lo);
        Address b = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(hi);
        Listing lst = currentProgram.getListing();
        InstructionIterator it = lst.getInstructions(a, true);
        FunctionManager fm = currentProgram.getFunctionManager();
        while (it.hasNext()) {
            Instruction i = it.next();
            if (i.getAddress().compareTo(b) > 0) break;
            Function f = fm.getFunctionContaining(i.getAddress());
            println(i.getAddress() + " " + i + "   [" + (f==null?"?":f.getName()+"@"+f.getEntryPoint()) + "]");
        }
    }
}
