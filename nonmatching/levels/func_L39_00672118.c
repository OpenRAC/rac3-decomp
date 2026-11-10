/* Near miss, ported from rac4-decomp's func_00546940 (cross-game near pair). NEAR: case order/values recovered from jtbl (3,1,2,4,5,6,9,7,10 -> 0..8, 8 default; blocks match) but switch index reg: ours reuses $a0 for value-1 and sll before lui, retail keeps $a0 and uses $v1/$a0 for table load; 5 variants same */
s32 func_L39_00672118(u32 value)
{
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
