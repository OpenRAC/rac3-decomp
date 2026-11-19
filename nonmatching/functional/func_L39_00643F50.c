/* functional: medium-high. Same structure and frame size as retail (296 words differ, scheduling/register order); per-slot loop over 6 players x 2 objects: copies player transform into each object, three branches (disabled slot, table-flagged, normal), then the shared-camera object. Retail loop-exit order for j (i in {1,3,4} run both objects) kept. Block at 0x2528!=0 sets pitch -pi/2. */
typedef int u128_t __attribute__((mode(TI)));
extern u8 D_L39_0049C890[];
extern u8 D_L39_0047ABA8[];
extern u8 D_L39_00246100[];
extern u8 D_L39_00246118[];
extern void func_003C48A8(void *, void *);
extern void func_003C6FE0(void *);
extern void func_003C7C38(void *);
extern s32 func_L39_00648AE0(u8 *, s32);
extern s32 func_L39_006319D8(u8 *, s32);
extern void func_0038D590(void *, void *);
extern void func_L39_006445F8(u8 *, void *, void *, s32, s32, u8 *);
extern void func_L39_00644878(u8 *, u8 *, u8 *, s32);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038D308(void *, void *);
extern s32 func_L39_006212E8(u8 *);
extern void func_0038D570(void *, void *);

void func_L39_00643F50(u8 *s, u8 *p) {
    u8 *r3d00, *r4100, *r4200;
    s32 i, j, k, fp;
    u8 *slot;
    u8 *obj;
    s32 f16, r19;
    s32 w;
    u8 *e;

    if (p == 0)
        p = *(u8 **)(s + 0x2524);
    r3d00 = s + 0x3D00;
    r4100 = s + 0x4100;
    r4200 = s + 0x4200;
    for (i = 0; i < 6; i++) {
        slot = s + i * 0x50;
        j = 0;
        for (;;) {
            obj = (j == 1) ? *(u8 **)(slot + 0x454) : *(u8 **)(slot + 0x450);
            fp = j + 1;
            if (obj != 0) {
                *(unsigned long *)(obj + 0x38) = *(unsigned long *)(*(u8 **)(s + 0x2524) + 0x38);
                k = i ? fp : 0;
                if (slot[0x46A] != 0) {
                    *(u128_t *)(slot + 0x430) = *(u128_t *)(s + k * 64 + 0x670);
                    func_003C48A8(s + k * 64 + 0x640, slot + 0x440);
                    func_003C6FE0(obj);
                    func_003C7C38(obj);
                    *(u16 *)(obj + 0x34) &= 0xFEFB;
                    goto after;
                }
                *(u128_t *)(obj + 0x10) = *(u128_t *)(s + k * 64 + 0x670);
                w = 0;
                if (*(s32 *)(s + 0x24AC) != 0) {
                    w = *(s32 *)(slot + 0x478);
                    if (func_L39_00648AE0(s, w))
                        e = D_L39_0049C890 + ((s8)D_L39_0049C890[w * 128 + 0x21] << 7);
                    else
                        e = D_L39_0049C890 + w * 128;
                    w = (s8)e[0xB] != 0;
                }
                if (!w) {
                    f16 = 0;
                    if (i == 0) {
                        s32 v = (*(s32 *)(s + 0x474) == 2) ? *(s32 *)(s + 0x478) : -1;
                        f16 = (v == 6 || v == 12);
                    }
                    r19 = func_L39_006319D8(s, i);
                    *(u16 *)(obj + 0x34) |= 0x106;
                    if (!f16 && r19 == 0)
                        func_003C6FE0(obj);
                    func_0038D590(obj + 0xC0, s + k * 64 + 0x640);
                    func_003C7C38(obj);
                    if ((u8)(*(*(u8 **)(s + 0x2524) + 0x42) - 0x40) < 2)
                        *(f32 *)(obj + 0xC) += 1800.0f;
                    if (f16) {
                        func_L39_006445F8(s, D_L39_0047ABA8, r3d00, *(s32 *)(obj + 0x24), 0, p);
                        *(u8 **)(obj + 0x58) = r3d00;
                        *(u8 **)(obj + 0x5C) = r3d00;
                        *(s32 *)(obj + 0x44) = 0;
                        *(s32 *)(obj + 0x40) = 0;
                    } else if (r19 != 0) {
                        if (j == 0) {
                            func_L39_006445F8(s, D_L39_00246100, r4100, *(s32 *)(obj + 0x24), 0, p);
                            *(u8 **)(obj + 0x58) = r4100;
                            *(u8 **)(obj + 0x5C) = r4100;
                        } else {
                            func_L39_006445F8(s, D_L39_00246118, r4200, *(s32 *)(obj + 0x24), 0, p);
                            *(u8 **)(obj + 0x58) = r4200;
                            *(u8 **)(obj + 0x5C) = r4200;
                        }
                        *(s32 *)(obj + 0x44) = 0;
                        *(s32 *)(obj + 0x40) = 0;
                    }
                } else {
                    func_003C6FE0(obj);
                    if (*(s32 *)(s + 0x24AC) == 0 || i != 0)
                        func_003C48A8(s + k * 64 + 0x640, obj + 0xF0);
                    else
                        func_L39_00644878(s, obj, s + 0x640, 1);
                    func_003C7C38(obj);
                    *(u16 *)(obj + 0x34) |= 6;
                }
                if (*(u8 **)(s + 0x251C) != 0) {
                    u8 *o2 = *(u8 **)(s + 0x251C);
                    if (*(s32 *)(s + 0x2528) == 0) {
                        s32 v = (*(s32 *)(slot + 0x474) == 2) ? *(s32 *)(slot + 0x478) : -1;
                        if (v == 10) {
                            *(u128_t *)(o2 + 0x10) = *(u128_t *)(s + k * 64 + 0x670);
                            func_0038D590(*(u8 **)(s + 0x251C) + 0xC0, s + k * 64 + 0x640);
                            *(u16 *)(obj + 0x34) |= 1;
                        } else {
                            s32 v2 = (*(s32 *)(slot + 0x474) == 2) ? *(s32 *)(slot + 0x478) : -1;
                            if (v2 == 11) {
                                f32 m[16];
                                if (func_L39_00648AE0(s, 10))
                                    e = D_L39_0049C890 + ((s8)D_L39_0049C890[0x521] << 7);
                                else
                                    e = D_L39_0049C890 + 0x500;
                                func_003C2EC0(*(u8 **)(s + 0x2524), (s8)e[0xA], m);
                                *(u128_t *)(*(u8 **)(s + 0x251C) + 0x10) = *(u128_t *)(m + 12);
                                func_0038D590(*(u8 **)(s + 0x251C) + 0xC0, m);
                            }
                        }
                    } else {
                        f32 vv[4];
                        vv[0] = 0.0f;
                        vv[1] = 0.0f;
                        vv[2] = 0.0f;
                        vv[3] = 0.0f;
                        vv[1] += -1.5707963705062866f;
                        func_0038D308(*(u8 **)(s + 0x251C) + 0xC0, vv);
                        *(u128_t *)(*(u8 **)(s + 0x251C) + 0x10) = *(u128_t *)(s + 0xA0);
                    }
                    {
                        s32 r = func_L39_006212E8(s);
                        if ((u32)(r - 10) >= 2 && r != -1)
                            s[0x1A0E] = 1;
                    }
                }
after:
                if (i != 0)
                    goto next;
                func_0038D570(s + 0x1380, obj + 0xC0);
                *(u128_t *)(s + 0x13B0) = *(u128_t *)(obj + 0x10);
            }
next:
            if (!(fp < 2))
                break;
            j = fp;
            if (i == 1 || i == 3 || i == 4)
                continue;
            break;
        }
    }
}
