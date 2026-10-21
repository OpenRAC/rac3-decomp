/* US draft of func_003ABBE8 (rac3-uya-decomp func_003A6640, commit 13cf5c5), names moved to PAL addresses
   where known. Not carried: differs: did not build, or built to other bytes, in PAL. */


/* localdecomp:start func_003ABBE8 */
typedef struct { u8 p0[4]; f32 *f4; u8 p8[0x28]; u32 f30; u32 f34; } O_A6640;
void func_003ABBE8(O_A6640 *o, u32 n) {
    u32 a = o->f34; u32 m;
    if (a < n) m = a; else m = n;
    if ((f32)a == 0.0f) { *o->f4 = 0.0f; } else { *o->f4 = (f32)m / (f32)o->f34 * (f32)o->f30; }
}
/* localdecomp:end func_003ABBE8 */
