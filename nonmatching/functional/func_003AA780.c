/* functional: high. Codex near-miss draft verified against the PAL assembly with three fixes: the x screen scale and the matrix handed to func_0038DA20 are gp-0x4840 = D_001D8070 (the draft had D_001D8090, a wrong name); the scratchpad is reached through D_70000000 (no literal 0x70001FC0/0x70002000) and is not volatile (CPU-written scratch data). 313 words differ (packing order, gp vs lui, scheduling). Compiles in 3AA060.c context (O_A4DC8, D_001D8064). */
typedef struct { unsigned long tex; u16 image1, image0; s16 width, height; } Texture_003AA780;
typedef struct { s16 count0, count2, h4, texture_count, anim_count; u8 pA[6]; void *geometry; u8 *commands; Texture_003AA780 *textures; u8 *images; void *p20; s32 mode; s32 extra; } Asset_003AA780;
typedef struct { void *image0; u16 zero, base0; void *image1; u8 width, height; u16 base1; } Upload_003AA780;
typedef unsigned int Quad_003AA780 __attribute__((mode(TI)));
extern s32 D_1D4BB0 __attribute__((section(".data")));
extern s32 D_1D9BFC __attribute__((section(".data")));
extern s32 D_1D4BC0 __attribute__((section(".data")));
extern s32 D_1D4BC4 __attribute__((section(".data")));
extern s32 D_1D4BD0 __attribute__((section(".data")));
extern s32 D_1D4BD4 __attribute__((section(".data")));
extern Upload_003AA780 D_225C00[];
typedef struct { u8 p[0xB0]; f32 x, y; } Projection_003AA780;
extern Projection_003AA780 D_225900;
extern u8 *D_1DA050 __attribute__((section(".data")));
extern f32 D_001D8060;
extern f32 D_001D8070[];
extern f32 D_001D8094 __attribute__((section(".data")));
extern f32 D_002259B0 __attribute__((section(".data")));
extern f32 D_002259B4 __attribute__((section(".data")));
extern u8 D_00143950[];
extern Quad_003AA780 D_001D8020;
extern unsigned long D_70000000[];
void func_003AA780(O_A4DC8 *object, f32 x, f32 y, s32 color, f32 animation, f32 *matrix)
{
    extern void func_003AA328(void);
    extern void func_0038D200(f32 *, void *, f32);
    extern void func_0038DA20();
    extern void func_0038D680();
    extern void func_003AA168(O_A4DC8 *, void *, f32);
    extern void func_003A08E8(void *, void *, s32, s32);
    extern void func_003A0A28(void *, void *, s32, s32, s32);
    Asset_003AA780 *o = (Asset_003AA780 *)object;
    f32 transformed[16];
    s32 i, base, base0, base1, width, height, n;
    Texture_003AA780 *t;
    Upload_003AA780 *upload;
    unsigned long tex, tag;
    u8 *command;
    s32 reg;
    unsigned long *packet;
    unsigned long *vertex;
    if ((color >> 24) == 0) return;
    for (i = 0; i < o->texture_count; i++) {
        t = &o->textures[i];
        base = D_1D4BB0;
        n = D_1D9BFC;
        width = t->width;
        height = t->height;
        base0 = base >> 8;
        base += 0x400;
        base1 = base >> 8;
        { s32 exponent = width - 6;
          if (exponent < 0) exponent = 0;
          tex = ((unsigned long)base1 | ((unsigned long)(1 << exponent) << 14))
            | ((((long)(u16)t->width << 48) >> 22) | 0x1300000)
            | (((long)(u16)t->height << 48) >> 18)
            | (((long)base0 << 37) | ((unsigned long)1 << 34))
            | ((unsigned long)1 << 63);
        }
        D_1D4BB0 = base + (1 << (width + height));
        t->tex = tex;
        if (n < 64) {
            upload = &D_225C00[n];
            upload->base0 = base0;
            upload->zero = 0;
            upload->image0 = o->images + t->image0 * 16;
            upload->image1 = o->images + t->image1 * 16;
            upload->width = t->width;
            upload->base1 = base1;
            upload->height = t->height;
            D_1D9BFC = n + 1;
        }
    }
    func_003AA328();
    if (D_001D8064) {
        matrix[10] *= D_001D8060 * 1.1260000467300415f;
        matrix[0] *= 1.1799999475479126f;
    }
    func_0038D200(matrix + 12, matrix + 12, 166.66600036621094f);
    D_001D8094 = -((f32)(D_1D4BC4 >> 1) / D_002259B4);
    D_001D8070[0] = (f32)(D_1D4BC0 >> 1) / D_002259B0;
    if (D_00143950[0xAD]) D_001D8094 *= 0.7500000596046448f;
    func_0038DA20(transformed, D_001D8070, matrix);
    transformed[12] += (f32)D_1D4BD0 + x * 16.0f;
    transformed[13] += (f32)D_1D4BD4 + y * 16.0f;
    func_0038D680((u8 *)D_70000000 + 0x1FC0);
    if (o->anim_count) func_003AA168(object, (u8 *)D_70000000 + 0x2000, animation);
    if (!o->mode) func_003A08E8(o->geometry, transformed, o->count0, color);
    else func_003A0A28(o->geometry, transformed, o->count0, o->extra, color);
    tag = 0x80000004CC007FFBUL;
    if (o->texture_count) { command = o->commands; reg = 0x5C; }
    else { command = o->commands + 4; reg = 0x4C; }
    for (i = 0; i < o->count2; i++) {
        if (o->texture_count && (*(s32 *)command >> 8) == -1) {
            n = command[0];
            if (n < o->texture_count) tag = o->textures[n].tex;
            else tag = 0x80000004CC007FFBUL;
            i--;
        } else {
            ((u32 *)D_1DA050)[0] = 0x10000008;
            ((u32 *)D_1DA050)[1] = 0;
            ((u32 *)D_1DA050)[2] = 0;
            ((u32 *)D_1DA050)[3] = 0x50000008;
            packet = (unsigned long *)D_1DA050;
            D_1DA050 = (u8 *)(packet + 2);
            *(Quad_003AA780 *)(packet + 2) = D_001D8020;
            packet = (unsigned long *)D_1DA050;
            D_1DA050 = (u8 *)(packet + 2);
            packet[2] = tag;
            packet = (unsigned long *)D_1DA050;
            packet[1] = reg;
            vertex = D_70000000 + command[0] * 4;
            packet[2] = vertex[0]; packet[3] = vertex[1]; packet[4] = vertex[2];
            vertex = D_70000000 + command[1] * 4;
            packet[5] = vertex[0]; packet[6] = vertex[1]; packet[7] = vertex[2];
            vertex = D_70000000 + command[3] * 4;
            packet[8] = vertex[0]; packet[9] = vertex[1]; packet[10] = vertex[2];
            vertex = D_70000000 + command[2] * 4;
            packet[11] = vertex[0]; packet[12] = vertex[1]; packet[13] = vertex[2];
            D_1DA050 += 0x70;
        }
        command += 4;
    }
}
