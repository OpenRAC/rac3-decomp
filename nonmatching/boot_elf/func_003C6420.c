/* Near miss of func_003C6420 with its file's own flags: tools/check.py reports 29 diff
   (the version it replaces: 33).
   What differs: body is byte-exact (only the PAL frame-rate constants changed: 0.020000001f /
   0.00040000002f instead of the US draft's 1/60 and 1/3600); all 29 remaining diffs are the
   callee-saved stack slots: retail keeps $s0-$s7,$fp,$ra in 16-byte `sq` slots (frame 0xC0,
   stack args at 0xC0/0xC8/0xD0) while the file's `-fopt-stack` makes gcc save them with `sd`
   in 8-byte slots (frame 0x70, args at 0x70/0x78/0x80) - no C wording changes that on this
   compiler, it needs the file split at 0x003C6420 without `-fopt-stack` plus `func_003C6420`
   in config/boot_elf/sq_ra_funcs.txt (both outside work/)
*/

/* US draft of func_003C6420 (rac3-uya-decomp func_003C62D0, commit 13cf5c5), names moved to PAL addresses
   where known. PAL change: the frame rate constants are the PAL ones (the retail code
   multiplies by 0x3CA3D70B and 0x39D1B718, i.e. 1/50 and 1/2500, where the US draft used
   1/60 and 1/3600).  The rest of the body already matches retail byte for byte. */


/* localdecomp:start func_003C6420 */
typedef struct { u8 key; u8 b1; u8 pad[2]; f32 f4, f8, fC, f10, f14, f18, f1C; } E3C;
typedef struct { u8 pad[0x14]; E3C *e; } P3C;
typedef struct { u8 pad[0xC]; u8 n; u8 pad2[0x3B]; P3C *arr[1]; } S3C;
typedef struct { u8 pad[0x24]; S3C *set; } O3C;
extern s32 func_00382848();
extern f32 func_003828C0(f32, f32);
s32 func_003C6420(O3C *obj, s32 key, s32 *idx, f32 *o1, f32 *o2, f32 *o3, f32 *o4, f32 *o5, f32 *o6, f32 *o7, u8 *o8) {
    E3C *e;
    s32 cnt = 0;
    s32 r;
    s32 i;
    s32 j;
    for (j = 0; j < obj->set->n; j++) {
        if (obj->set->arr[j]->e) {
            if (obj->set->arr[j]->e->key == key) cnt++;
        }
    }
    if (cnt == 0) return 0;
    r = func_00382848(cnt);
    for (i = 0; i < obj->set->n; i++) {
        e = obj->set->arr[i]->e;
        if (e && e->key == key) {
            if (r != 0) {
                r--;
            } else {
                *o1 = e->f8 * 0.020000001f;
                *o2 = e->fC * 0.020000001f;
                *o3 = e->f10 * 0.00040000002f;
                *o4 = e->f14 * 0.00040000002f;
                *o7 = e->f4 * 0.00040000002f;
                *o5 = e->f18;
                *o6 = e->f1C;
                if (e->b1) *o8 = e->b1;
                *o1 = func_003828C0(*o1 * 0.87f, *o1 * 1.13f);
                *o2 = func_003828C0(*o2 * 0.85f, *o2 * 1.15f);
                *o3 = func_003828C0(*o3 * 0.85f, *o3 * 1.15f);
                *o7 = func_003828C0(*o7 * 0.9f, *o7 * 1.1f);
                *idx = i;
                return 1;
            }
        }
    }
    return 0;
}
/* localdecomp:end func_003C6420 */
