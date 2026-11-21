/* functional: medium. Compiles, not byte-exact; callee roles by use only; unlike retail the two entry lists are probed with a shared inline helper; case-7 tail checks (func_006D9C90 record, id>=0, two list scans) read from asm, semantics of the lists not verified */
typedef s32 (*VFn_h)();
extern u8 D_00247D38[];
extern u8 D_00247D60[];
extern u8 D_00247D68[];
extern u8 *D_00247914;
extern void *D_0024D760[];
extern u8 *D_001E2050_sda;
extern u8 *D_001DC204_sda;
extern u8 D_001DC628_sda[];
extern void func_L39_006915C8(void *);
extern void func_L39_00691900(void *);
extern s32 func_L39_0068AEF8(void *, s32);
extern s32 func_0059A970(s32);
extern void func_00120048(char *, char *, ...);
extern void func_L39_00689E58(void *, void *, u32, f32, f32);
extern void func_L39_00688340(s32, s32, s32);
extern void func_L39_0068B2F8(void *, s32, s32);
extern void func_L39_00687450(void *, void *, void *, s32, s32, s32, s32);
extern s32 func_001205B0(void *, void *);
extern u8 *func_L39_006D9C90(s32, void *);
extern void func_L39_006D6398(void *, s32);
extern s32 func_L39_006CDC30(void *, s32);
extern s32 func_L39_006CDDB0(void *, s32);
extern void func_L39_006B5288(s32, s32, s32);
extern s32 func_L39_006872E8(void *, void *, void *, s32, f32, s32);
extern void func_L39_0068A2D0(void *, s32, s32, s32, f32, f32);
extern void func_L39_00689F00(void *, s32, s32, s32, f32, f32, f32, f32, f32, f32);

#define VCALL_h(o, off) (*(VFn_h *)(*(u8 **)((o) + 0x60) + (off)))

static __inline__ u8 *list_h(u8 *base)
{
    u8 *list = 0;
    if (*base != 0) {
        s32 idx = *(s32 *)(base + 4);
        if (idx >= 0) list = base + idx * 12 + 0x28;
    }
    return list;
}

static __inline__ s32 has_id_h(u8 *list, s32 id)
{
    s32 k, n;
    if (list != 0) {
        n = *(s32 *)(list + 4);
        if (n > 0) {
            u8 **items = *(u8 ***)(list + 8);
            for (k = 0; k < n; k++)
                if (*(s32 *)(items[k] + 0x1C) == id) return 1;
        }
    }
    return 0;
}

s32 func_L39_00690DE8(u8 *self, s32 code)
{
    char buf[0x20];
    char buf2[0x70];
    f32 pos[2];
    u8 *obj, *g;
    s32 n, sel, r, id;

    func_L39_006915C8(self);
    obj = *(u8 **)(self + 0x110);
    n = VCALL_h(obj, 0x78)(obj);
    if (n > 0) {
        obj = *(u8 **)(self + 0x110);
        VCALL_h(obj, 0x20)(obj, 3, 0);
        func_L39_00691900(self);
    } else {
        VCALL_h(obj, 0x20)(obj, 2, 0);
    }
    if (func_L39_0068AEF8(self, code) == 1) return 1;

    if (*(s32 *)(self + 0x290) == 0) {
        func_00120048(buf, (char *)D_00247D60, (char *)func_0059A970(0xF8F));
        func_L39_00689E58(self, buf, 0x706EC8FF, 1.0f, 1.0f);
    } else {
        func_L39_00689E58(self, D_00247D38, 0x706EC8FF, 1.0f, 1.0f);
    }

    sel = *(s32 *)(self + 0x290);
    if (sel != 0) {
        obj = *(u8 **)(self + 0x110);
        n = VCALL_h(obj, 0x78)(obj);
        if (n > 0 && (u32)(code - 3) < 2) {
            func_L39_00688340(3, 0, 0);
            func_L39_0068B2F8(self, 0, 0);
            return 1;
        }
    }
    sel = *(s32 *)(self + 0x290);
    if (code == 1 && sel == code) {
        func_L39_00688340(3, 0, 0);
        func_L39_0068B2F8(self, 3, 0);
        return 1;
    }
    if (code == 2 && sel == 3) {
        func_L39_00688340(3, 0, 0);
        func_L39_0068B2F8(self, 1, 0);
        return 1;
    }
    if (sel == 0) {
        if ((u32)(code - 3) < 2) {
            func_L39_00688340(3, 0, 0);
            func_L39_0068B2F8(self, 1, 0);
            return 1;
        }
        if (code == 1) {
            obj = *(u8 **)(self + 0x110);
            if (VCALL_h(obj, 0x8C)(obj) == 0) return 1;
        }
        if (code == 2) {
            u8 *base = self + 0x110;
            s32 cur, cnt;
            obj = *(u8 **)(base + *(s32 *)(self + 0x290) * 4);
            cur = VCALL_h(obj, 0x8C)(obj);
            obj = *(u8 **)(base + *(s32 *)(self + 0x290) * 4);
            cnt = VCALL_h(obj, 0x78)(obj);
            if (cur == cnt - 1) return 1;
        }
    }

    if (code == 7) {
        func_L39_00688340(4, 0, 0);
        sel = *(s32 *)(self + 0x290);
        if (sel == 2) {
            *(s32 *)(D_00247914 + 0x284) = 0x1E;
            return 1;
        }
        if (sel == 3) {
            *(s32 *)(D_00247914 + 0x284) = 3;
            return 1;
        }
        if (sel == 0) {
            obj = *(u8 **)(self + 0x110);
            r = VCALL_h(obj, 0x8C)(obj);
            if (r != -1) {
                func_L39_006B5288(*(s32 *)(D_00247914 + 0xD0), *(s32 *)(self + r * 4 + 0x2B4), 1);
                *(s32 *)(D_00247914 + 0x284) = 0x1B;
                return 1;
            }
        } else if (sel == 1) {
            u8 *rec, *lst;
            u8 *list;
            buf[0] = 0;
            func_L39_00687450(D_00247914, D_00247D38, buf, 0, 0xF, 1, 0);
            if (func_001205B0(buf, D_00247D38) != 0) {
                g = D_001E2050_sda;
                lst = *(u8 **)(g + 0x34);
                rec = func_L39_006D9C90(*(s32 *)(g + 0x48), buf);
                if (rec == 0) {
                    func_00120048(buf2, (char *)func_0059A970(0x1175), buf);
                    func_L39_006872E8(D_00247914, buf2, D_00247D38, 4, 0.6f, 0);
                    return 1;
                }
                id = *(s32 *)(rec + 0x18);
                if (id < 0) {
                    func_L39_006872E8(D_00247914, (void *)func_0059A970(0x128F), D_001DC628_sda, 4, 0.6f, 0);
                    return 1;
                }
                if (has_id_h(list_h(lst), id)) return 1;
                list = *(u8 **)((u8 *)D_0024D760[0] + 0x40);
                if (has_id_h(list_h(list), id))
                    func_L39_006D6398(list, id);
                if (func_L39_006CDC30(lst, id) != 0) {
                    self[0x2A8] = 1;
                    func_00120048(buf2, (char *)D_00247D68, (char *)func_0059A970(0xF98));
                    func_L39_006872E8(D_001DC204_sda, buf2, D_001DC628_sda, 4, 0.6f, 0);
                } else {
                    func_00120048(buf2, (char *)D_00247D68, (char *)func_0059A970(0xF99));
                    func_L39_006872E8(D_00247914, buf2, D_001DC628_sda, 4, 0.6f, 0);
                }
                return 1;
            }
        }
    }

    if (code == 8 && *(s32 *)(self + 0x290) == 0) {
        s32 item, res;
        obj = *(u8 **)(self + 0x110);
        r = VCALL_h(obj, 0x8C)(obj);
        if (r == -1) return 1;
        item = *(s32 *)(self + r * 4 + 0x2B4);
        if (item < 0) return 1;
        id = func_0059A970(0x1034);
        obj = *(u8 **)(self + 0x110);
        r = VCALL_h(obj, 0x98)(obj);
        func_00120048(buf, (char *)id, (char *)r);
        res = func_L39_006872E8(D_00247914, buf, (void *)func_0059A970(0x1031), 3, 0.6f, 0);
        if (res != 1) return 1;
        func_L39_006CDDB0(*(u8 **)((u8 *)D_0024D760[0] + 0x34), item);
        self[0x2A8] = res;
        return 1;
    }

    func_L39_0068A2D0(self, 0, 3, 3, 2.0f, 2.0f);
    sel = *(s32 *)(self + 0x290);
    if (sel == 0) {
        obj = *(u8 **)(self + 0x110);
        if (VCALL_h(obj, 0x9C)(obj, &pos[0], &pos[1]) != 0)
            func_L39_00689F00(self, 0, 3, 3, pos[0] + 0.175f, pos[1], 0.35f, 0.035f, 0.027f, 0.25f);
    } else {
        obj = *(u8 **)(self + 0x110 + sel * 4);
        VCALL_h(obj, 0x30)(obj, &pos[0], &pos[1]);
        func_L39_00689F00(self, 0, 3, 3, pos[0], pos[1], 0.43f, 0.032f, 0.027f, 0.25f);
    }
    return 0;
}
