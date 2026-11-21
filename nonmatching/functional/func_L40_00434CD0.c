/* exact: byte-identical at L40, L41, L50 (file flags). EXACT at level 40 and also at levels 41 and 50 with the file's flags */
/* localdecomp:start func_L40_00434CD0 */
extern s32 D_001A5E40[];
extern s32 D_001A6A80[];
extern void func_003C2880(u8 *);
extern u8 *func_L39_0066C828(u8 *, s32, s32);
extern void func_L01_004450F0(void *, s32, s32);

void func_L40_00434CD0(u8 *m) {
    u8 *v = *(u8 **)(m + 0x68);
    if (m[0x20] == 0) {
        if (D_001A5E40[0] != 0 || D_001A6A80[0] == 0) {
            func_003C2880(m);
        } else {
            func_L39_0066C828(m, -1, 1);
            m[0x30] = 0x10;
            *(s16 *)(v + 0x1E) = 0xA0;
            *(s16 *)(v + 0x1C) = -3;
            func_L01_004450F0(m, 1, -1);
        }
    }
}
/* localdecomp:end func_L40_00434CD0 */
