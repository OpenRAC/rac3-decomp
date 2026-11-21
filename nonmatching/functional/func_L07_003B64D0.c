/* functional: high. EXACT at level_07 (MATCH) with the file's flags; draft note says .rodata lands elsewhere in a level build (landing issue, not behaviour). Only 1 place. */
void func_L07_003B64D0(u8 *obj, s32 state) {
    extern void func_003C3A10(void *, s32, s32, s32);
    extern f32 func_L07_003B6DC8(u8 *, u8 *);
    u8 *p = *(u8 **)(obj+0x68);
    switch (state) {
    case 1: case 3: case 16:
        break;
    case 2:
        if (obj[0x43] != 22) func_003C3A10(obj,22,0,0);
        break;
    case 4:
        if (obj[0x43] != 1) func_003C3A10(obj,1,0,7);
        break;
    case 5:
        if (obj[0x43] != 0) func_003C3A10(obj,0,0,8);
        break;
    case 6:
        if (obj[0x43] != 17) func_003C3A10(obj,17,0,7);
        break;
    case 7:
        if (obj[0x43] != 5) func_003C3A10(obj,5,0,3);
        break;
    case 8:
        if (func_L07_003B6DC8(obj,p+0x80) > 0.0f) {
            if (obj[0x43] != 7) func_003C3A10(obj,7,0,2);
        } else {
            if (obj[0x43] != 8) func_003C3A10(obj,8,0,2);
        }
        break;
    case 9:
        if (obj[0x43] != 9) func_003C3A10(obj,9,0,3);
        break;
    case 10:
        if (obj[0x43] != 10) func_003C3A10(obj,10,0,3);
        break;
    case 11:
        if (obj[0x43] != 19) func_003C3A10(obj,19,0,3);
        break;
    case 12:
        if (obj[0x43] != 11) func_003C3A10(obj,11,0,3);
        break;
    case 13:
        if (obj[0x43] != 12) func_003C3A10(obj,12,0,3);
        break;
    case 14:
        if (obj[0x43] != 13) func_003C3A10(obj,13,0,3);
        break;
    case 15:
        if (obj[0x43] != 18) func_003C3A10(obj,18,0,3);
        break;
    case 17:
        if (obj[0x43] != 14) func_003C3A10(obj,14,0,25);
        break;
    case 18:
        if (obj[0x43] != 24) func_003C3A10(obj,24,0,3);
        break;
    case 19:
        if (obj[0x43] != 2) func_003C3A10(obj,2,0,3);
        *(f32 *)(obj+0x48) = 0.5f;
        break;
    case 20:
        if (obj[0x43] != 3) func_003C3A10(obj,3,0,3);
        break;
    case 21:
        if (obj[0x43] != 4) func_003C3A10(obj,4,0,3);
        *(f32 *)(obj+0x48) = 0.5f;
        break;
    case 22:
        if (obj[0x43] != 22) func_003C3A10(obj,22,0,3);
        break;
    case 23:
        if (obj[0x43] != 23) func_003C3A10(obj,23,0,3);
        break;
    case 24:
        if (obj[0x43] != 20) func_003C3A10(obj,20,0,3);
        break;
    case 25:
        if (obj[0x43] != 25) func_003C3A10(obj,25,0,3);
        break;
    }
    func_L01_004450F0(obj,state,-1);
}
