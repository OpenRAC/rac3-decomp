/* Ported from rac4-decomp's func_L00_00540310 (a twin of this function's code), names renamed from retail's
   relocations; 5 instruction(s) still differ under this file's flags. */


s32 func_L39_00504500(s32 arg0) {
    s32 result=func_L39_004DBA08();
    *(s32*)(result+56)=arg0;
    return result;
}