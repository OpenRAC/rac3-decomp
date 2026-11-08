/* func_L39_004B95C0: near miss 7 diff (w2 p2w2). 128 bytes, 1 level. Switch on id, 125-entry table (cases 4..128) mapped from jtbl_00474B40; body returns match.
   Remaining: dispatch prologue: retail addiu a0,a0,-4 in place + nop slot + lw %lo(table)(v1); ours uses v1 and lui/addiu. */
int func_L39_004B95C0(unsigned int id)
{
    switch (id) {
    case 116: return -0x269;
    case 4:
    case 113: return -0x259;
    case 12: return -0x26D;
    case 22:
    case 125: return -0x270;
    case 127: return -0x268;
    case 110:
    case 128: return -0x26C;
    case 111: return -0x26A;
    case 104: return -0x272;
    case 118: return -0x26B;
    case 16:
    case 115: return -0x271;
    }
    return -0x271;
}
