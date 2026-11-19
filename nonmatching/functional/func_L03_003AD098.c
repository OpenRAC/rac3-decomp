/* functional: medium. Rotating-turret/dial object update: state 0-3 pick a +-10/+-20 degree step and +-g/2g step on the target angle t[1], claims a handle, updates two rotation matrices (v+0xF0,v+0x170) and sets state 4 when t[1]==t[0]. Not byte-exact (goto/duplicate blocks merged into a switch); gp float D_001DE5C8. */
extern u8 D_001A30B0[];
extern f32 D_001DE5C8;
extern s32 func_003A52A0(s32, s32, void *);
extern f32 func_L03_003AD030(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_L01_0044E850(void *, void *, s32, f32, f32);
extern void func_0038D308(void *, void *);

s32 func_L03_003AD098(u8 *obj) {
    u8 *v = *(u8 **)(obj + 0x68);
    s32 *vw = (s32 *)v;
    u8 *owner = *(u8 **)v;
    u8 *tv = *(u8 **)(owner + 0x68);
    s32 *t = (s32 *)tv;
    s32 st = t[2];
    s32 h;
    f32 delta;
    f32 step;
    s32 hasStep;

    hasStep = 1;
    switch (st) {
    case 0: delta = 10.0f; step = -D_001DE5C8; break;
    case 1: delta = -10.0f; step = D_001DE5C8; break;
    case 2: delta = 20.0f; step = -(D_001DE5C8) + -(D_001DE5C8); break;
    case 3: delta = -20.0f; step = D_001DE5C8 + D_001DE5C8; break;
    default: hasStep = 0; break;
    }
    if (hasStep) {
        h = vw[6];
        if (h == -1 || *(u8 **)(D_001A30B0 + (h << 7) + 0xDC) != obj || D_001A30B0[(h << 7) + 0xD0] == 0) {
            vw[6] = func_003A52A0((st == 0 || st == 2) ? 1 : 0, 4, obj);
        }
        *(f32 *)(v + 0x48) = func_L03_003AD030(*(f32 *)(v + 0x48), delta);
        *(f32 *)(v + 0x150) = func_0038DAB8(0.0f, *(f32 *)(v + 0x48) * 0.017453292f);
        func_L01_0044E850(*(void **)(v + 0x1C), v + 0xF0, 0, 2.88f, 2.88f);
        *(f32 *)(v + 0x1D0) = func_0038DAB8(0.0f, *(f32 *)(v + 0x48) * 0.017453292f);
        func_L01_0044E850(*(void **)(v + 0x1C), v + 0x170, 1, 2.88f, 2.88f);
        ((f32 *)t)[1] = func_L03_003AD030(((f32 *)t)[1], step);
    }
    *(f32 *)(owner + 0xF0) = func_0038DAB8(0.0f, ((f32 *)t)[1] * 0.017453292f);
    func_0038D308(owner + 0xC0, owner + 0xF0);
    if (((f32 *)t)[1] == ((f32 *)t)[0]) {
        t[2] = 4;
        func_003A52A0(2, 0, obj);
        return 1;
    }
    return 0;
}
