package fr.ubordeaux.deptinfo.compilation.lea.stree;

import fr.ubordeaux.deptinfo.compilation.lea.type.TypeException;

public class StreeLSHIFTAFF extends StreeOpeAff {

	public StreeLSHIFTAFF(Stree left, Stree right) throws TypeException, StreeException {
		super(left, right, new StreeLSHIFT(left,right));
	}

}
