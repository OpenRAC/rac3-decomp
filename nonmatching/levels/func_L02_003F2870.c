/* Level 02 (Florana), PAL. 27 diff with check.py --target level_02. about 27 differences: gcc compiles the leading `if (call != 0) return 1;` as `beqz` plus a `b` to a duplicated epilogue where retail uses `bnez` with `li $v0,1` in the delay slot and one shared epilogue; the table `lui` and the 0x14 `lui` land in different registers; the loop exit falls straight into the epilogue in retail. */
typedef struct { int key; int off; } E_3F2870;
extern int func_L01_0041A4F0(int, int);
extern E_3F2870 D_L02_002CF100[];
__asm__(".extern D_L02_002CF100, 16");
extern unsigned char D_0014271D;
__asm__(".extern D_0014271D, 16");
extern unsigned char D_001D5570[];
int func_L02_003F2870(int a, int b) {
    E_3F2870 *e;
    if (func_L01_0041A4F0(a, b) != 0) return 1;
    if (a == 0x67) return D_0014271D != 0;
    for (e = D_L02_002CF100; e->key != 0; e++) {
        if (a == e->key) {
            if (e->off != b && D_001D5570[e->off] == 0) return 0;
            return 1;
        }
    }
    return 0;
}
