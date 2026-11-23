/* functional: medium. mat1 is three rows (func_0038D308 writes 0x30 bytes; a one-row local overran the frame); vsubs are retail's VU0 ops so the VU0 state callees see is retail's. Written from the asm (no draft); compiles under file flags, not byte-exact (463 words differ, frame size within 0x10). Control flow and call order follow retail block by block. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_003287D8;
typedef struct {
    u8 p0[8];
    s32 (*fn8)(void *);
    u8 pc[4];
    s32 (*fn10)(void *);
} Cls_003287D8;
typedef struct { u8 p0[4]; u8 *next; } Node_003287D8;
extern u8 D_001A4C60[];
extern s32 D_001D4BC0;
extern s32 D_001D4BC4;
extern f32 D_L01_001DC0E8;
extern f32 D_L01_001DC0EC;
extern f32 D_L01_001DCA34;
extern f32 D_L01_001DCA38;
extern f32 D_L01_001DCA44;
extern f32 D_L01_001DCA48;
extern f32 D_L01_001DCA4C;
extern f32 D_L01_001DCA50;
extern f32 D_L01_001DCA54;
extern f32 D_L01_001DCA5C;
extern f32 D_L01_001DCA6C;
extern f32 D_L01_001DCA70;
extern f32 D_L01_001DCA74;
extern f32 D_L01_001DCA78;
extern s32 D_L01_001DCA7C;
extern s32 D_L01_001DCA80;
extern s32 D_L01_001DCA8C;
extern s32 D_L01_001DCA94;
extern s32 D_L01_001DCA98[4];
extern u8 *D_001A71A0;
extern V_003287D8 D_L01_001E2DD0;
void func_L01_003287D8(void) {
    extern void func_0038CB78(void *, s32, s32);
    extern long func_00389598(s32);
    extern void func_0038D308();
    extern void func_0038CE90(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_0038D5F0(void *, void *, void *);
    extern void func_L01_0040EE50(void *, void *);
    extern s32 func_00396968(s32, s32);
    extern void func_003972A0(s32, void *, f32, f32, f32, f32, f32);
    extern s32 func_L01_00449050(void *);
    extern void func_L01_00328598(u8 *, s32, void *, void *, long);
    extern f32 func_0038CE68(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_0038CEA8(void *);
    extern void func_0038D000(void *, void *, void *);
    extern void func_0038B4D0(s32, s32, s32, s32, s32, s32, s32, s32, long, long);
    extern s32 func_L01_003257E8(void);
    extern u8 *func_L01_003B3508(void);
    extern void func_L01_00326D98(void);
    s32 buf[72]; /* retail's contiguous stack flags: seen[4], seen_row[16][4], seen2[4] */
    V_003287D8 rot, axis, mat1[3], mat2[3], vec, proj, scr; /* mat1: func_0038D308 writes three rows (0x30 bytes) */
    s32 colour[4];
    u8 *vars;
    u8 **objs;
    Cls_003287D8 **classes;
    Cls_003287D8 *cls;
    Cls_003287D8 *cls2;
    u8 *moby;
    u8 *pos;
    long icon;
    s32 i, k, t, first;
    f32 w, x, y, dist, f20, wf, hf, dot, px, py, bw, bh;
    func_0038CB78(&buf[0], 0, 0x10);
    func_0038CB78(&buf[4], 0, 0x100);
    func_0038CB78(&buf[68], 0, 0x10);
    vars = *(u8 **)(func_L01_003257E8() + 0x68);
    objs = (u8 **)(vars + 0x2A0);
    classes = (Cls_003287D8 **)(vars + 0x160);
    icon = func_00389598(D_L01_001DCA7C);
    rot.x = 0.0f; rot.y = 0.0f; rot.z = -1.5707964f; rot.w = 0.0f;
    func_0038D308(mat1, &rot);
    mat2[1] = D_L01_001E2DD0;
    mat2[2] = *(V_003287D8 *)(D_001A71A0 + 0xE0);
    func_0038CE90(&mat2[0], &mat2[1], &mat2[2]);
    axis = *(V_003287D8 *)(D_001A71A0 + 0xE0);
    func_0038CF68(&mat2[0], &mat2[0], 1.0f);
    func_0038D5F0(&mat2[0], &mat2[0], mat1);
    func_L01_0040EE50(&mat2[0], &mat2[0]);
    /* background panel */
    wf = (f32)D_001D4BC0;
    hf = (f32)D_001D4BC4;
    w = D_L01_001DCA6C;
    colour[0] = colour[1] = colour[2] = colour[3] = D_L01_001DCA8C;
    px = (D_L01_001DCA74 - w) * wf;
    bw = (w + w) * wf;
    py = (D_L01_001DCA78 - D_L01_001DCA70) * hf;
    bh = (D_L01_001DCA70 + D_L01_001DCA70) * hf;
    func_003972A0(func_00396968(0xE99A, 3), colour, px, py, bw, bh, 0.0f);
    first = D_L01_001DCA98[0];
#define SKIPPED(m) ((*(long *)((m) + 0x30) & ((long)0x8208 << 29)) == ((long)0x8200 << 23) && *(s32 *)((m) + 0x98) == 0)
    /* pass 1: draw the primary category, note which others are present */
    for (i = 0; i < 16; i++) {
        moby = objs[i];
        if (!moby) continue;
        cls = classes[i];
        if (!cls->fn10) continue;
        do {
            Node_003287D8 *node = (Node_003287D8 *)func_L01_00449050(moby);
            t = cls->fn10(moby);
            if (t && !cls->fn8(moby) && !SKIPPED(moby)) {
                if (t == first) func_L01_00328598(moby, t, &axis, mat2, icon);
                else { buf[t] = 1; buf[4 + i * 4 + t] = 1; }
            }
            moby = node->next;
        } while (moby);
    }
    cls2 = 0;
    if (*(s32 *)(vars + 0x60)) {
        cls2 = ((Cls_003287D8 *(*)(void))func_L01_00326D98)();
        moby = *(u8 **)(vars + 0x60);
        while (moby) {
            Node_003287D8 *node = (Node_003287D8 *)func_L01_00449050(moby);
            t = cls2->fn10(moby);
            if (t && !cls2->fn8(moby)) {
                if (t == first) func_L01_00328598(moby, t, &axis, mat2, icon);
                else buf[68 + t] = 1;
            }
            moby = node->next;
        }
    }
    /* pass 2: the remaining categories in priority order */
    for (k = 1; k < 4; k++) {
        t = D_L01_001DCA98[k];
        if (!buf[t]) continue;
        for (i = 0; i < 16; i++) {
            if (!buf[4 + i * 4 + t]) continue;
            moby = objs[i];
            cls = classes[i];
            if (!moby) continue;
            do {
                Node_003287D8 *node = (Node_003287D8 *)func_L01_00449050(moby);
                if (cls->fn10(moby) == t && !cls->fn8(moby) && !SKIPPED(moby))
                    func_L01_00328598(moby, t, &axis, mat2, icon);
                moby = node->next;
            } while (moby);
        }
    }
    if (*(s32 *)(vars + 0x60)) {
        cls2 = ((Cls_003287D8 *(*)(void))func_L01_00326D98)();
        for (k = 1; k < 4; k++) {
            t = D_L01_001DCA98[k];
            if (!buf[68 + t]) continue;
            moby = *(u8 **)(vars + 0x60);
            if (!moby) continue;
            do {
                Node_003287D8 *node = (Node_003287D8 *)func_L01_00449050(moby);
                s32 r = cls2->fn10(moby);
                if (r && !cls2->fn8(moby)) {
                    if (r == t) func_L01_00328598(moby, r, &axis, mat2, icon);
                    else buf[68 + r] = 1;
                }
                moby = node->next;
            } while (moby);
        }
    }
    /* player marker */
    pos = func_L01_003B3508();
    if (pos) {
        /* retail's VU0 vsub (vf1 = pos - hero, vf2 = hero): the VU0 registers it leaves reach later
         * retail callees, so they are left as retail leaves them */
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(vec) : "m"(*(V_003287D8 *)pos), "m"(*(V_003287D8 *)D_001A4C60) : "vf1", "vf2");
        dot = func_0038CE68(&vec, &axis);
        func_0038CE20(&proj, &axis, dot);
        __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(vec) : "m"(vec), "m"(proj) : "vf1", "vf2");
        dist = func_0038CEA8(&vec);
        if (D_L01_001DCA44 < dist) dist = D_L01_001DCA44;
        else if (dist < D_L01_001DCA48) dist = D_L01_001DCA48;
        f20 = dist * (1.0f / D_L01_001DCA44);
        func_0038D000(&vec, &vec, mat2);
        func_0038CF68(&scr, &vec, f20 * D_L01_001DCA54);
        w = D_L01_001DCA5C;
        x = scr.x * D_L01_001DCA4C + D_L01_001DCA34;
        y = scr.y * D_L01_001DCA50 + D_L01_001DCA38;
        bw = w + w;
        x -= w;
        y -= w;
        func_0038B4D0((s32)(x * D_L01_001DC0E8), (s32)(y * D_L01_001DC0EC),
                      (s32)(bw * D_L01_001DC0E8), (s32)(bw * D_L01_001DC0EC),
                      0, 0, D_L01_001DCA80, D_L01_001DCA80, D_L01_001DCA94, icon);
    }
}
