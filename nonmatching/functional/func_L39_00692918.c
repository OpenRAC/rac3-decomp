/* functional: medium. Not byte-exact (compiles, frame 0x10 smaller); vtable offsets 0x1C/0x6C/0x88/0x8C of widget at +0x110 named by offset only; strcpy/strlen/memcpy-like callees assumed from use */
typedef s32 (*VFn_a)();
extern s32 func_001206F4(void *, s32);
extern s32 func_00120884(void *);
extern void func_005958F8(void *, void *, s32);
extern void func_L39_006D2500(void *, s32, s32);
extern u8 *func_L39_006D31B8(void *, s32, s32);

void func_L39_00692918(u8 *self)
{
    u8 *ptrs[16];
    u8 bufs[16][0x50];
    u8 *mgr = *(u8 **)((u8 *)D_L39_0024D760 + 0x38);
    u8 *list;
    u8 *obj;
    s32 flag = self[0x2AC];
    s32 n, cnt, i, cur, sel, r;

    if (flag == 1) {
        if (mgr[0x4E4] != 0) return;
        if (self[0x2AD] == 0 && self[0x4F9] == 0 && self[0x745] == 0) {
            func_L39_006D2500(mgr, 0, 0);
            self[0x2AD] = flag;
            self[0x2AC] = 0;
            *(s32 *)(self + 0x2A8) = *(s32 *)(mgr + 0x4EC);
        }
    }
    if (mgr[0x4E4] != 0) return;
    if (self[0x2AD] == 0) return;
    if (*(s32 *)(mgr + 0x4EC) == *(s32 *)(self + 0x2A8)) return;

    list = 0;
    if (mgr[0x4DC] != 0) {
        s32 idx = *(s32 *)(mgr + 0x4E0);
        if (idx >= 0) list = mgr + idx * 12 + 0x4F4;
    }
    flag = self[0x2AC];
    self[0x2AD] = 0;
    if (flag == 1 && mgr[0x4E4] == 0) {
        func_L39_006D2500(mgr, 0, 0);
        self[0x2AC] = 0;
        *(s32 *)(self + 0x2A8) = *(s32 *)(mgr + 0x4EC);
    }
    if (list == 0) return;
    if (*(s32 *)(mgr + 0x4EC) == *(s32 *)(self + 0x2A8)) return;
    *(s32 *)(self + 0x2A8) = *(s32 *)(mgr + 0x4EC);
    obj = *(u8 **)(self + 0x110);
    n = *(s32 *)(list + 4);
    *(s32 *)(self + 0x2B0) = 0;
    sel = 0;
    r = (*(VFn_a *)(*(u8 **)(obj + 0x60) + 0x8C))(obj);
    cur = -1;
    if (r != -1) cur = *(s32 *)(self + r * 4 + 0x2B4);
    i = 0;
    if (n > 0 && *(s32 *)(self + 0x2B0) < 16) {
        do {
            u8 *item = ((u8 **)*(u8 **)(list + 8))[i];
            if (*(s32 *)(item + 0x1C) == *(s32 *)mgr) {
                u8 *p;
                s32 c = *(s32 *)(self + 0x2B0);
                *(s32 *)(self + 0x2B4 + c * 4) = *(s32 *)(item + 0x1C0);
                p = func_L39_006D31B8(mgr, *(s32 *)(item + 0x20), *(s32 *)(item + 0x20));
                func_001206F4(self + 0x2F4 + *(s32 *)(self + 0x2B0) * 32, (s32)(p + 0x20));
                c = *(s32 *)(self + 0x2B0);
                ptrs[c] = self + 0x2F4 + c * 32;
                *(s32 *)(self + 0x2B0) = c + 1;
                if (cur == *(s32 *)(self + 0x2B4 + c * 4)) sel = c;
            }
            i++;
        } while (i < n && *(s32 *)(self + 0x2B0) < 16);
    }
    cnt = *(s32 *)(self + 0x2B0);
    for (i = 0; i < cnt; i = i + 1) {
        s32 len = func_00120884(ptrs[i]);
        func_005958F8(bufs[i], ptrs[i], len);
        ptrs[i] = bufs[i];
        cnt = *(s32 *)(self + 0x2B0);
    }
    obj = *(u8 **)(self + 0x110);
    (*(VFn_a *)(*(u8 **)(obj + 0x60) + 0x6C))(obj, *(s32 *)(self + 0x2B0), ptrs);
    obj = *(u8 **)(self + 0x110);
    (*(VFn_a *)(*(u8 **)(obj + 0x60) + 0x88))(obj, sel);
    cnt = *(s32 *)(self + 0x2B0);
    obj = *(u8 **)(self + 0x110);
    if (cnt > 0) {
        if (*(s32 *)(obj + 4) < 3)
            (*(VFn_a *)(*(u8 **)(obj + 0x60) + 0x1C))(obj, 3, 0);
    } else {
        if (*(s32 *)(obj + 4) >= 3)
            (*(VFn_a *)(*(u8 **)(obj + 0x60) + 0x1C))(obj, 2, 0);
    }
}
