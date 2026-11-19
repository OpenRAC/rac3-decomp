/* functional: high. EXACT with @ps2as (check.py --as ps2as: MATCH); with the file's current flags (no @ps2as) 235 words differ, scheduling only. The file 3BE8E0.c has other matched functions under the plain flag line, so landing it exact needs a part split at 0x003BEB68 (or proof the others still match with @ps2as). US C with the two PAL changes: particle lifetime 0x43 (US 0x50) and fall rate 1/50 (0x3CA3D70B, US 1/60). Uses the file context's typedefs and externs (S_3B9160, Q_3B92B8, V4_3B92B8, func_003BEA10 ...). */
void func_003BEB68(u8 *obj, V4_3B92B8 *pos, V4_3B92B8 *tgt, f32 *ang) {
    V4_3B92B8 m0, m10, m20, m30, m40, m50, m60, m70;
    Q_3B92B8 x, y;
    f32 one, a, a1, a2, q;
    f32 l;
    one = 1.0f;
    m0 = *(V4_3B92B8 *)(obj + 0xC0);
    m10 = *(V4_3B92B8 *)(obj + 0xD0);
    func_0038D348((s32)&m0, (s32)&m0, one);
    q = 0.1f;
    func_0038D348((s32)&m10, (s32)&m10, one);
    func_0038D270(&m20, &m0, &m10);
    m30 = m10;
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*tgt));
    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*pos));
    __asm__("vsub.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(m50) : "j"(x));
    m40 = m50;
    l = func_0038D288(&m40);
    func_0038D218(&m50, &m30, l * q);
    a = *ang;
    a1 = a + 2.09439611f;
    a2 = a + 4.18878937f;
    if (3.14159274f < a1) a1 -= 6.28318548f;
    if (3.14159274f < a2) a2 -= 6.28318548f;

    func_0038D348((s32)&m50, (s32)&m0, func_0038D478(a) * 0.25f);
    func_0038D348((s32)&m60, (s32)&m20, func_0038D478(a) * 0.25f);
    {
        Q_3B92B8 x, y, z;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*pos));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(m50));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(m70) : "j"(x));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(m70));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(m60));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(m70) : "j"(x));
    }
    func_003BEA10((Q_3B9160 *)&m70, (f32 *)&m30, 0x43, 0x808080, func_00382848(0xC), 0x40, 0x20,
                  func_003828C0(0.2f, 0.8f) * 210000.0f, 0.0f, -(func_003828C0(0.04f, q) * 0.0200000014f));

    func_0038D348((s32)&m50, (s32)&m0, func_0038D478(a1) * 0.25f);
    func_0038D348((s32)&m60, (s32)&m20, func_0038D478(a1) * 0.25f);
    {
        Q_3B92B8 x, y, z;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(*pos));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(m50));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(m70) : "j"(x));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(m70));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(m60));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(m70) : "j"(y));
    }
    func_003BEA10((Q_3B9160 *)&m70, (f32 *)&m30, 0x43, 0x808080, func_00382848(0xC), 0x40, 0x20,
                  func_003828C0(0.2f, 0.8f) * 210000.0f, 0.0f, -(func_003828C0(0.04f, q) * 0.0200000014f));

    func_0038D348((s32)&m50, (s32)&m0, func_0038D478(a2) * 0.25f);
    func_0038D348((s32)&m60, (s32)&m20, func_0038D478(a2) * 0.25f);
    {
        Q_3B92B8 x, y, z;
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(m50));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*pos));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(y) : "j"(y), "j"(x));
        __asm__("sqc2 %1, %0" : "=m"(m70) : "j"(y));
        __asm__("lqc2 %0, %1" : "=j"(x) : "m"(m70));
        __asm__("lqc2 %0, %1" : "=j"(y) : "m"(m60));
        __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
        __asm__("sqc2 %1, %0" : "=m"(m70) : "j"(x));
    }
    func_003BEA10((Q_3B9160 *)&m70, (f32 *)&m30, 0x43, 0x808080, func_00382848(0xC), 0x40, 0x20,
                  func_003828C0(0.2f, 0.8f) * 210000.0f, 0.0f, -(func_003828C0(0.04f, q) * 0.0200000014f));

    *ang -= func_003828C0(0.02f, 0.2f);
    if (*ang < -3.14159274f) *ang += 6.28318548f;
}
