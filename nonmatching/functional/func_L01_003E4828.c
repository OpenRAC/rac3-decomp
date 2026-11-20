/* functional: high. vadd.xyz written as plain float adds (w lane left as the first operand's, as retail does); arg order entry,target,height(f12),from_ground(a2) */

/* localdecomp:start func_L01_003E4828 */
extern void func_0038CE20(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_L01_003E4198(u8 *, void *, s32);

void func_L01_003E4828(Entry_3E6C58 *entry, q128 *target, f32 height, s32 from_ground) {
    u8 *e = (u8 *)entry;
    u8 *p = e + 0x60;
    f32 v[8];
    func_0038CE20(&v[0], e + 0x80, height);
    if (from_ground != 0) {
        func_L01_003E4198(e, &v[4], 1);
    } else {
        func_L01_003E4028(*(u8 **)(e + 0x50), &v[4]);
    }
    v[0] = v[0] + v[4];
    v[1] = v[1] + v[5];
    v[2] = v[2] + v[6];
    func_0038CE20(target, p + 0x30, func_0038CE68(p + 0x30, &v[0]));
}
/* localdecomp:end func_L01_003E4828 */
