/* Near miss, ported from rac4-decomp's func_00546940 (cross-game near pair). NEAR: switch with retail jtbl order (3,1,2,4,5,6,9,7,10 -> results 0..8; 8 default); u8 param gives 9 diff: index reg (addiu $v1 vs in-place $a0) and lui/sll order of table address; known switch dispatch-register blocker */
s32 func_L39_0067A6D0(u8 value) {
    s32 result = -1;
    switch (value) {
    case 3:
        result = 0;
        break;
    case 1:
        result = 1;
        break;
    case 2:
        result = 2;
        break;
    case 4:
        result = 3;
        break;
    case 5:
        result = 4;
        break;
    case 6:
        result = 5;
        break;
    case 9:
        result = 6;
        break;
    case 7:
        result = 7;
        break;
    case 10:
        result = 8;
        break;
    }
    return result;
}
