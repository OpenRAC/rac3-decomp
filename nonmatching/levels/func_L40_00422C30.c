/* Ported from rac4-decomp's func_L41_00411AD8 (a twin of this function's code), names renamed from retail's
   relocations; 3 instruction(s) still differ under this file's flags. */
typedef struct Type2 {
    char _p0[0xF0];
    s32 fF0;
} Type2;
typedef struct Type1 {
    char _p0[0xAC];
    Type2 *fAC;
    char _pB0[0xBC - 0xB0];
    s16 fBC;
} Type1;
extern s32 func_L40_00422B60(s32 arg0);

s32 func_L40_00422C30(Type1 *arg0) {
    Type2 *p = arg0->fAC;
    switch (arg0->fBC) {
    case 0x1ABA: return 0x108A;
    case 0x1ABB: return 0x1089;
    case 0x1ABC: return 0x1096;
    case 0x1ABD: return 0x1087;
    case 0x1ABE: return 0x10A4;
    case 0x1ABF: return 0x10A5;
    case 0x1AC0: return 0x10A7;
    case 0x1AC1: return 0x1098;
    case 0x1AF2: return 0x1AF3;
    case 0x1B09: return 0x1B0C;
    case 0x1B0A: return 0x1B0D;
    case 0x1B0B: return 0x1B0E;
    case 0x1F1E: return func_L40_00422B60(p->fF0);
    }
    return -1;
}