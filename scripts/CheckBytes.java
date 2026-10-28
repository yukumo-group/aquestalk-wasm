import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.listing.*;
public class CheckBytes extends GhidraScript {
  public void run() throws Exception {
    AddressSpace sp = currentProgram.getAddressFactory().getDefaultAddressSpace();
    for (long a=0x104eec; a<0x104f40; a++) {
      Address ad = sp.getAddress(a);
      Instruction ins = getInstructionAt(ad);
      Data dt = getDataAt(ad);
      if (ins!=null) println(String.format("%x INS %s", a, ins));
      else if (dt!=null) println(String.format("%x DATA %s %s", a, dt.getDataType().getName(), dt));
      else { println(String.format("%x UNDEF", a)); }
    }
  }
}
