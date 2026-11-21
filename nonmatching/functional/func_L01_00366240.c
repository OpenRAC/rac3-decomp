/* functional: high. 113 words differ (VU0 scheduling, constants hoisting, gp addressing); D_L01_001DD7xx names from file context style; math sequence verified op by op against asm */
/* localdecomp:start func_L01_00366240 */
static __inline__ void sub_ba_00366240(void *d, void *a, void *b) {
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(S_38C110v *)d) : "m"(*(S_38C110v *)b), "m"(*(S_38C110v *)a) : "vf1", "vf2");
}
static __inline__ void add_ba_00366240(void *d, void *a, void *b) {
    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(S_38C110v *)d) : "m"(*(S_38C110v *)b), "m"(*(S_38C110v *)a) : "vf1", "vf2");
}
static __inline__ void add_ab_00366240(void *d, void *a, void *b) {
    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(*(S_38C110v *)d) : "m"(*(S_38C110v *)a), "m"(*(S_38C110v *)b) : "vf1", "vf2");
}
extern f32 D_L01_001DD784;
extern s32 D_L01_001DD778;
extern s32 D_L01_001DD7DC;
extern s32 D_L01_001DD774;
extern u8 D_L01_0028CAA0[];
extern S_38C110v D_L01_0028E390[];
void func_L01_00366240(void *arg) {
    extern f32 func_0038CEA8(void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_003661D8(void *);
    S_38C110v a, b, c;
    u8 *row;
    s32 offset;
    u8 *obj;
    f32 length;
    D_L01_001DD784 *= 0.5f;
    D_L01_001DD778 = 1;
    D_L01_001DD7DC = 0;
    D_L01_001DD774 = 1;
    offset = 0;
    row = D_L01_0028CAA0;
    do {
        obj = *(u8 **)(D_L01_0028CAA0 + 0x1C + offset);
        if (obj != 0) {
            *(u8 **)(D_L01_0028CAA0 + 0x1C + offset) = 0;
            sub_ba_00366240(&a, &D_L01_0028E390[*(s16 *)row], &D_L01_0028E390[1 + *(s16 *)row]);
            length = func_0038CEA8(&a);
            func_0038CE20((s128 *)&a, (s128 *)&a, *(f32 *)(D_L01_0028CAA0 + offset + 4) / length);
            add_ba_00366240(&b, &D_L01_0028E390[1 + *(s16 *)row], &a);
            sub_ba_00366240(&c, obj + 0x10, &b);
            func_0038CF68(&c, &c, 0.03f);
            func_0038CE20((s128 *)&a, (s128 *)&a, 0.1f / length);
            add_ab_00366240(obj + 0x30, &c, &a);
            if (*(s32 *)(row + 0xC) != 0) *(s16 *)(obj + 0xA) = 10;
            else *(s16 *)(obj + 0xA) = 70;
            *(s32 *)(row + 0xC) = 0;
        }
        row += 0x20;
        offset += 0x20;
    } while ((s32)row < (s32)(D_L01_0028CAA0 + 0x1900));
    func_L01_003661D8(arg);
}
/* localdecomp:end func_L01_00366240 */
