/* functional: high. No draft; written from asm. Loop, offsets (table +0x74/+0x34, entry 8 bytes: word, h4, b6, b7), callee args (word,base>>8,0x1B,b6,b7,c) and delay-slot values ( base advanced by 4<<(b6+b7), D_001D5D50 stored every iteration, even the last) checked. Bytes differ (68 words: frame, lui vs gp addressing of the pointers declared in the file). */
typedef struct { u8 p0[0x14]; s32 a[8]; s32 b[16]; s32 c[1]; } S_38E930;
typedef struct { u32 w0; u16 h4; u8 b6; u8 b7; } E_38E930;
extern S_38E930 * volatile D_001D9EA0_00393548;
extern E_38E930 *D_001D9EAC_00393548;
extern volatile s32 D_001A1F08_00393548[];
extern u32 D_001D5D50;
extern void func_003933B0_00393548();
extern void func_00397D60(s32, s32, s32, s32, s32, s32);
void func_00393548(s32 a, s32 unused, s32 c) {
    s32 base, start, end, i, hi, sh;
    E_38E930 *e;
    if (((s32 *)((u8 *)D_001D9EA0_00393548 + 0x74))[a] == 0) {
        func_003933B0_00393548(0);
    }
    base = D_001A1F08_00393548[0];
    start = (a != 0) ? D_001D9EA0_00393548->b[a - 1] : 0;
    end = D_001D9EA0_00393548->b[a];
    i = start;
    while (i < end) {
        e = &D_001D9EAC_00393548[i];
        hi = base >> 8;
        i++;
        sh = e->b6 + e->b7;
        func_00397D60(e->w0, hi, 0x1B, e->b6, e->b7, c);
        base += (1 << sh) * 4;
        D_001D9EAC_00393548[i - 1].h4 = hi;
        D_001D5D50 = base;
    }
}
