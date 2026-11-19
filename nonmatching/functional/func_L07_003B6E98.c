/* functional: high. near-miss draft (2 words order only); callees translated to catalogue names */
/* localdecomp:start func_L07_003B6E98 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_003B6E98;
void func_L07_003B6E98(u8 *obj, u8 joint) {
    extern void func_003C2F58(void *, s32, void *);
    extern f32 func_L07_003B6DC8(u8 *, u8 *);
    extern f32 func_0038DBA0(f32, f32);
    extern f32 func_003C3BE8(f32, f32, f32);
    extern f32 func_0038CF38(void *, void *);
    extern f32 func_0038D160(f32, f32);
    extern u8 *func_L07_003B1958(void *, Quad_003B1958 *, u8, f32, f32);
    extern void func_L07_00473C80(void *, s32, u32, s32, s32, s32, s32, s32, s32, f32, f32, f32);
    Vec_003B6E98 pos, target;
    u8 *v = *(u8 **)(obj + 0x68);
    f32 t, offset, pitch, scale;
    joint += 2;
    func_003C2F58(obj, joint, &pos);
    t = func_0038DBA0(func_L07_003B6DC8(obj, v + 0x80), *(f32 *)(obj + 0xF8)) / 0.5235987901687622f;
    if (t > 1.0f) t = 1.0f;
    offset = -0.5f;
    scale = 1.0f;
    t = func_003C3BE8(offset, -2.0f, t);
    target = *(Vec_003B6E98 *)(v + 0x80);
    target.z += t;
    pitch = func_0038D160(func_0038CF38(&pos, &target), target.z - pos.z);
    if (*(s16 *)(v + 0x31A) != 0) pitch *= 1.0f + *(s16 *)(v + 0x31A) / 90.0f;
    {
        typedef struct { u8 pad[0x44]; u8 kind; } Kind_003B6E98;
        pitch = -pitch;
        func_L07_003B1958(obj, (Quad_003B1958 *)&pos, ((Kind_003B6E98 *)v)->kind, *(f32 *)(obj + 0xF8), pitch);
    }
    if ((u32)(v[0x31D] - 1) < 2) offset = 0.5f;
    func_L07_00473C80(obj, joint, 0xBF804020, 0, 7, 0, 1, 53, 0, 735000.0f, 21000.0f, offset);
    func_L07_00473C80(obj, joint, 0xBFA04020, 0, 7, 0, 1, 53, 0, 525000.0f, 21000.0f, offset);
    func_L07_00473C80(obj, joint, 0xC0FFFFFF, 0, 7, 0, 1, 53, 0, 367500.0f, 21000.0f, offset);
    func_L07_00473C80(obj, joint, 0xB0FFFFFF, 0, 7, 0, 1, 53, 0, 262500.0f, 21000.0f, offset);
}
/* localdecomp:end func_L07_003B6E98 */
