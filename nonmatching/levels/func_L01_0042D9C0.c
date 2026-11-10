/* Near miss, ported from rac2-decomp's func_00294D80 (cross-game near pair). NEAR: 2 instrs: constant bit63 synthesised ori 0x8000;dsll32 16 vs retail addiu -1;dsll32 31 (8 spellings fold the same); rest exact incl. D_L01_001DF97C with .extern hint 16 and D_L01_001E7880[]; all 34 places show same 2 diff */
typedef struct {
    u32 word0;
    u16 half4;
    u16 half6;
    u32 word8;
    u8 byteC;
    u8 byteD;
    u16 halfE;
} S_42D9C0;
__asm__(".extern D_L01_001DF97C, 16");
extern S_42D9C0 D_L01_001E7880[];
extern s32 D_L01_001DF97C;

unsigned long func_L01_0042D9C0(int a0, int a1, u32 a2, u32 a3, int arg5, int arg6)
{
    int shift;
    unsigned long value;
    unsigned long term;
    unsigned long term2;
    unsigned long result;
    int count;
    shift = a0 - 6;
    shift = (shift >= 0) ? shift : 0;
    shift = 1 << shift;
    value = (unsigned long)shift << 14;
    value |= (unsigned long)(arg6 >> 8);
    term = (unsigned long)a0 << 26;
    term |= 0x01300000;
    value |= term;
    value |= (unsigned long)a1 << 30;
    term2 = (unsigned long)(arg5 >> 8) << 37;
    term2 |= 0x400000000UL;
    value |= term2;
    result = value | 0x8000000000000000UL;
    count = D_L01_001DF97C;
    if (count < 0x40) {
        D_L01_001E7880[count].word0 = a2;
        D_L01_001E7880[count].half6 = arg5 >> 8;
        D_L01_001E7880[count].half4 = 0;
        D_L01_001E7880[count].word8 = a3;
        D_L01_001E7880[count].byteC = a0;
        D_L01_001E7880[count].byteD = a1;
        D_L01_001E7880[count].halfE = arg6 >> 8;
        D_L01_001DF97C = count + 1;
    }
    return result;
}
