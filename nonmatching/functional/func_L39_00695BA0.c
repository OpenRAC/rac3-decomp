/* functional: medium. Compiles, frame 0x10 larger than retail; text buffer size (<=0x50), the widget vtable slots (0x8C selected index, 0x98 text, 0x9C position) and callee roles named by use only; D_001E2050_sda vs D_0024D760[0] treated as two distinct pointers as in retail */
typedef s32 (*VFn_b)();
extern u8 D_00247FC0[];
extern u8 *D_00247914;
extern void func_L39_00695AE0(void *);
extern s32 func_L39_00695FC0(void *);
extern void func_L39_00696010(void *);
extern void func_L39_00689F00(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);
extern s32 func_L39_0068AEF8(void *, s32);
extern void func_L39_00687450(void *, void *, void *, s32, s32, s32, s32);
extern s32 func_001205B0(void *, void *);
extern s32 func_L39_006DD608(s32, void *, s32);
extern void func_L39_006CEEE0(void *, void *);
extern void func_L39_006CEA18(void *, s32);
extern void func_L39_006D03B8(void *, s32, s32, void *);
extern void func_L39_0068A2D0(void *, s32, s32, s32, f32, f32);
extern s32 func_L39_006872E8(void *, void *, void *, s32, f32, s32);
extern s32 func_0059A970(s32);
extern void func_00120048(char *, char *, ...);

s32 func_L39_00695BA0(u8 *self, s32 code)
{
    u8 buf[0x50];
    u8 *mgr, *s18, *s19, *obj;
    s32 sel, idx, id, r;

    func_L39_00695AE0(self);
    mgr = (u8 *)D_0024D760[0];
    s18 = *(u8 **)(mgr + 0x54);
    s19 = *(u8 **)(mgr + 0x38);
    func_L39_00689F00(self, 0, 3, 3, 1.5f, 1.5f, 0.325f, 0.035f, 0.045f, 0.1f);
    if (func_L39_00695FC0(self) != 0) return 1;
    func_L39_00696010(self);
    if (func_L39_0068AEF8(self, code) != 0) return 1;

    if (code == 6) {
        func_L39_00687450(D_00247914, D_00247FC0, self + 0x2B4, 0, 0x10, 0, 0);
        if (func_001205B0(self + 0x2B4, D_00247FC0) != 0) {
            if (func_L39_006DD608((s32)s18, self + 0x2B4, 0) != 0) {
                func_L39_006CEEE0(s19, self + 0x2B4);
                func_L39_006CEA18(s19, 0);
            }
        }
        return 1;
    }
    if (code == 7) {
        sel = *(s32 *)(self + 0x290);
        if (sel == 2) {
            u8 *tgt;
            obj = *(u8 **)(self + 0x118);
            idx = (*(VFn_b *)(*(u8 **)(obj + 0x60) + 0x8C))(obj);
            if (idx < 0) return 1;
            s18 = (u8 *)*(s32 *)(self + idx * 4 + 0x308);
            if ((s32)s18 < 0) return 1;
            id = func_0059A970(0x149E);
            obj = *(u8 **)(self + 0x118);
            r = (*(VFn_b *)(*(u8 **)(obj + 0x60) + 0x98))(obj);
            func_00120048((char *)buf, (char *)id, r);
            r = func_L39_006872E8(D_00247914, buf, (void *)func_0059A970(0x1031), 3, 0.6f, 0);
            if (r == 1) {
                func_L39_006D03B8(s19, (s32)s18, 1, D_00247FC0);
                tgt = (u8 *)D_001E2050_sda;
            } else if (r == sel) {
                func_L39_006D03B8(s19, (s32)s18, 2, D_00247FC0);
                tgt = (u8 *)D_0024D760[0];
            } else {
                tgt = (u8 *)D_001E2050_sda;
            }
            func_L39_006CEA18(*(u8 **)(tgt + 0x38), 0);
            self[0x2AC] = 1;
            return 1;
        }
    } else if (code == 8) {
        if (*(s32 *)(self + 0x290) == 2) {
            obj = *(u8 **)(self + 0x118);
            idx = (*(VFn_b *)(*(u8 **)(obj + 0x60) + 0x8C))(obj);
            if (idx < 0) return 1;
            s18 = (u8 *)*(s32 *)(self + idx * 4 + 0x308);
            if ((s32)s18 < 0) return 1;
            id = func_0059A970(0x1039);
            obj = *(u8 **)(self + 0x118);
            r = (*(VFn_b *)(*(u8 **)(obj + 0x60) + 0x98))(obj);
            func_00120048((char *)buf, (char *)id, r);
            r = func_L39_006872E8(D_00247914, buf, (void *)func_0059A970(0x1031), 3, 0.6f, 0);
            if (r != 1) return 1;
            func_L39_006D03B8(*(u8 **)((u8 *)D_0024D760[0] + 0x38), (s32)s18, 2, D_00247FC0);
            self[0x2AC] = r;
            return 1;
        }
    } else if (*(s32 *)(self + 0x290) == 2) {
        f32 pos[2];
        s32 n, flags;
        obj = *(u8 **)(self + 0x118);
        (*(VFn_b *)(*(u8 **)(obj + 0x60) + 0x9C))(obj, &pos[0], &pos[1]);
        obj = *(u8 **)(self + 0x110 + *(s32 *)(self + 0x290) * 4);
        r = (*(VFn_b *)(*(u8 **)(obj + 0x60) + 0x8C))(obj);
        n = *(s32 *)(self + 0x304) - 1;
        flags = (0 < r);
        if (r < n) flags |= 2;
        func_L39_0068A2D0(self, flags, 3, 3, 0.274f, pos[1] + -0.0015f);
        return 0;
    }
    func_L39_0068A2D0(self, 0, 3, 3, 2.0f, 2.0f);
    return 0;
}
