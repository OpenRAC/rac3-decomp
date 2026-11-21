/* functional: high. Skeleton pose evaluation: for each of n joints decodes the frame's 0x18-byte key record into a 0x40-byte matrix out[i]; if t has a fractional part >0.001 blends each joint with the next frame's (wrapping to frame 0 at nframes) via func_0038DE48(frac); then per joint builds the matrix from its rows (func_0038DD58) and, if the parent index (record+0x16) >= 0, concatenates with the parent (func_0038DA20). (s32)t is the EE's cvt.w.s (truncate). US draft's inline-asm cvt removed: plain casts, same value. Verified against PAL asm. */
typedef struct { u8 p0[0x16]; s16 h16; } F_3AA168;
typedef struct { u8 p0[4]; s16 n; u8 p6[2]; s16 nframes; s16 stride; u8 pC[0x14]; u8 *data; } A_3AA168;
typedef struct { f32 m[16]; } M_3AA168;
extern void func_0038DDF0(void *, void *);
extern void func_0038DE48(void *, void *, void *, f32);
extern void func_0038DD58(void *, void *, void *, void *);
extern void func_0038DA20(void *, void *, void *);

void func_003AA168(A_3AA168 *a, M_3AA168 *out, f32 t)
{
    f32 tmp[12];
    s32 i;
    s32 frame = (s32)t;
    f32 frac;
    u8 *src = a->data + frame * a->stride;

    for (i = 0; i < a->n; i++, src += 0x18) {
        func_0038DDF0(src, &out[i]);
    }
    frac = t - (f32)frame;
    if (0.001f < frac) {
        s32 next = frame + 1;
        if (!(next < a->nframes)) {
            next = 0;
        }
        src = a->data + next * a->stride;
        for (i = 0; i < a->n; i++, src += 0x18) {
            func_0038DDF0(src, tmp);
            func_0038DE48(&out[i], &out[i], tmp, frac);
        }
    }
    {
        F_3AA168 *f = (F_3AA168 *)(a->data + (s32)t * a->stride);
        s32 j;

        for (j = 0; j < a->n; j++, f++) {
            func_0038DD58(&out[j], &out[j].m[4], &out[j].m[8], &out[j]);
            if (f->h16 >= 0) {
                func_0038DA20(&out[j], &out[f->h16], &out[j]);
            }
        }
    }
}
