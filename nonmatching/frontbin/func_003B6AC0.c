/* US draft of func_003B6AC0 (rac3-uya-decomp func_003B15E0, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003B6AC0 */
typedef struct { u8 on; u8 pad[7]; } F;
typedef struct { void (*fn)(); s32 pad; } T;
extern s32 D_001D8A18_003B6AC0;
__asm__(".extern D_001D8A18_003B6AC0, 4");
extern F D_001D8A48_003B6AC0[1];
__asm__(".extern D_001D8A48_003B6AC0, 8");
extern T D_001D8A4C[1];
__asm__(".extern D_001D8A4C, 16");
typedef struct { s32 a[7]; } R;
extern R D_142430[];
extern void func_003B6848();
extern void func_003B6910();
extern void func_003B6970();
extern void func_003B69B0();
extern void func_003B6A98();
void func_003B6AC0(s32 unused) {
    s32 i;
    s32 m = D_001D8A18_003B6AC0;
    for (i = 0; i < 4; i++) {
        D_001D8A48_003B6AC0[i].on = 1;
        switch (m) {
        case 0: D_001D8A4C[i].fn = func_003B6970; break;
        case 1:
            D_001D8A4C[i].fn = func_003B6910;
            if (D_142430[i].a[12] == -1) D_001D8A4C[i].fn = func_003B6A98;
            break;
        case 2: D_001D8A4C[i].fn = func_003B6848; break;
        case 3: D_001D8A4C[i].fn = func_003B69B0; break;
        }
    }
}
/* localdecomp:end func_003B6AC0 */
