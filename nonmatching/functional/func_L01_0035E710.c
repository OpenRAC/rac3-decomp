/* functional: high. Types the draft took from a later file are redeclared locally (same layouts); vadd.xyz as float adds + w copy. */
typedef struct { u8 pad0[0x18]; u8 *moby; } CollHit_0035E710;
typedef struct { u8 pad0[0x18]; u8 b18; u8 b19; s16 source_class; u8 pad1C[0x14]; } DamageInfo_0035E710;
typedef struct { u8 p0; u8 kind; u8 pad[0xEE]; } Gun_0035E710;
extern u8 D_001A4BE0[];
extern CollHit_0035E710 D_L01_001EAA00;
extern u8 D_00142617[];
extern Gun_0035E710 D_L01_002C5600[];
void func_L01_0035E710(u8 *obj) {
    extern s32 func_L01_004CB2D8(void);
    extern void func_L01_004CAB30(void *, void *);
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    extern void func_0038CE20(s128 *, s128 *, f32);
    extern void func_L01_00446760(DamageInfo_0035E710 *, u8 *, s32, void *, f32);
    extern s32 func_003D4D00(void *, s32, f32, void *, void *);
    extern f32 func_L01_0040E548(void *, void *);
    extern void func_L01_0035EB20(void *);
    extern s32 func_L01_003303B8(u8 *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
        s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
    extern void func_003C2880(void *);
    extern s32 func_0038DC20(void *, f32);
    extern void func_L01_00404A10(void *, void *);
    extern void func_L01_0035EF20(u8 *);
    extern void func_L01_0035F048(void *, void *, void *);
    S_38C110v previous;
    S_38C110v push;
    DamageInfo_0035E710 info;
    u8 *v = *(u8 **)(obj + 0x68);
    u8 *hero;
    u8 *position;
    switch (obj[0x20]) {
    case 0:
        position = obj + 0x10;
        previous = *(S_38C110v *)(obj + 0x10);
        {
            f32 *vf = (f32 *)v;
            f32 *pp = (f32 *)(obj + 0x10);
            pp[0] = vf[0] + pp[0]; pp[1] = vf[1] + pp[1]; pp[2] = vf[2] + pp[2];
            pp[3] = vf[3]; /* vadd.xyz keeps the vars quad's w */
        }
        if (func_L01_004CB2D8()) func_L01_004CAB30(position, position);
        if (*(f32 *)(obj + 0x10) < 2.0f || *(f32 *)(obj + 0x10) > 1021.0f ||
            *(f32 *)(obj + 0x14) < 2.0f || *(f32 *)(obj + 0x14) > 1021.0f ||
            *(f32 *)(obj + 0x18) < 2.0f || *(f32 *)(obj + 0x18) > 1021.0f) goto destroy;
        ++*(s32 *)(v + 0x14);
        hero = D_001A4BE0;
        *(s32 *)(*(u8 **)(D_001A4BE0 + 0x25C0) + 0x98) = 0;
        if (func_003D3CB0(&previous, position, 0x20, obj, 0)) {
            u8 *hit = D_L01_001EAA00.moby;
            if (hit == 0 || hit != *(u8 **)(v + 0x1C)) {
                obj[0x20] = 1;
                *(s128 *)(obj + 0x10) = *(s128 *)((u8 *)&D_L01_001EAA00 + 0x20);
                push = *(S_38C110v *)v;
                func_0038CE20((s128 *)&push, (s128 *)&push, 3.0f);
                push.w = 5627.9248046875f;
                func_L01_00446760(&info, obj, *(s32 *)(v + 0x28), &push, *(f32 *)(v + 0x24));
                info.source_class = *(u16 *)(obj + 0xAA);
                info.b19 = 1;
                info.b18 = 0;
                if (D_L01_001EAA00.moby != 0) {
                    if (D_L01_001EAA00.moby != *(u8 **)(v + 0x1C))
                        func_003D4D00((u8 *)&D_L01_001EAA00 + 0x20, 0, 1.0f, obj, &info);
                } else {
                    func_003D4D00((u8 *)&D_L01_001EAA00 + 0x20, 0, 0.6f, obj, &info);
                }
            }
        }
        { u8 *m = *(u8 **)(D_001A4BE0 + 0x25C0);
          *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10); }
        if (*(s32 *)(v + 0x14) >= 151 || func_L01_0040E548(position, D_001A4BE0 + 0x80) > 6400.0f) goto destroy;
        break;
    case 1:
        if (((Gun_0035E710 *)((s32)D_L01_002C5600 + D_00142617[0] * 0xF0))->kind >= 2) {
            func_L01_0035EB20(obj + 0x10);
        } else {
            func_L01_003303B8(obj + 0x10, 0, 5, 2, 2, 2, 2, 0, 0.2f, 0.0f, 0.0f, 0.0f,
                0, 1, 0, 0, 0, 0, 0x1010000, 0, 0x388EF7, 0x63F7, 0x407FFF, 0x20FF, 0x8FFF, 0x3064FF,
                0x7F60A0FF, 0x280000FF, 0xFF6430, 0);
        }
        goto destroy;
    }
    goto draw;
destroy:
    func_003C2880(obj);
    return;
draw:
    push = *(S_38C110v *)(obj + 0x10);
    push.w = 0.5f;
    if (func_0038DC20(&push, 96.0f) > 0) {
        func_L01_00404A10(func_L01_0035EF20, obj);
        *(S_38C110v *)&info = *(S_38C110v *)(obj + 0x10);
        func_L01_0035F048(obj, &info, &previous);
    }
    return;
}
