/* US draft of func_003966D8 (rac3-uya-decomp func_00391E78, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: flags: the US matched it with `@ps2as` and without `-mno-split-addresses` (a single-function override). */


/* localdecomp:start func_003966D8 */
/* Needs S mode + @ps2as. The barrier keeps b loaded before h so b conflicts with e and takes $v1;
   the reused id variable puts the 2 in $a0; the volatile store keeps the D_001D5EA0 store out of the b delay slot. */
__asm__(".extern D_001D5EA4, 1");
__asm__(".extern D_001D5E98, 4");
typedef struct {
    u8 f0;
    u8 p1[0x37];
    u16 f38;
    u8 p3A[0x50];
    u16 f8A;
    u8 p8C[0xF0 - 0x8C];
} S_391E78;
extern u8 D_001D5EA4;
extern s32 D_001D5E98;
extern s32 D_001D5E9C;
extern s32 D_001D5EA0;
extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
extern s32 D_001427F0[];
extern S_391E78 D_001DAA40_003966D8[];
extern s32 func_00396690(void);
extern void func_003935B0(s32 id, s32 v);
extern void func_00396390();
extern void func_00397B10();
extern s32 func_003963C0(void);
extern void func_003938F8();
extern void func_0038F0F8();
extern s32 func_00396278();
void func_003966D8(void) {
    s32 r;
    u8 *p;
    u8 *s;
    s32 id;
    S_391E78 *e;
    u8 b;
    u16 h;
    s32 n;
    if (D_001D5EA4 != 0) return;
    if (D_001D5E98 != 0) return;
    r = func_00396690();
    p = D_001425C0 + r;
    e = &D_001DAA40_003966D8[*p];
    b = e->f0;
    __asm__ __volatile__("");
    h = e->f38;
    if (r != 0 && b != 0) {
        D_001D5E9C = r;
        *(volatile s32 *)&D_001D5EA0 = ((s32 (*)())func_00393348)(0x10, h, (s32)func_00396390, (s32)func_00397B10,
                                   (s32)func_003963C0, (s32)&D_001427F0[r],
                                   D_001DAA40_003966D8[*p].f8A);
    } else {
        s = D_001A4BE0;
        id = 2;
        n = -1;
        b = s[0x25E4];
        if (b == id) {
            id = D_001D5EA0;
            if (id != n) {
                func_003935B0(id, 0);
                D_001D5EA0 = n;
            }
            *(s16 *)(s + 0x1A88) = ((s32 (*)())func_00393348)(0x10, 0xFFFF, (s32)func_003938F8, (s32)func_0038F0F8,
                                                 (s32)func_00396278, (s32)(s + 0x1A84), 200);
        } else {
            id = D_001D5EA0;
            if (id != n) {
                func_003935B0(id, 0);
                D_001D5EA0 = n;
            }
        }
    }
}
/* localdecomp:end func_003966D8 */
