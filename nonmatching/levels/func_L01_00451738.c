/* func_L01_00451738: abs.s sits before the ld $ra (unscheduled fabsf); 2 diff
   Phase 2 w3 w7; Size 40, 34 places
   Draft uses __builtin_fabsf; retail order needs the asm trick (not allowed) */
#if 0
extern f32 func_L01_00451700(s32, Vec4 *, s32);
f32 func_L01_00451738(s32 a0, Vec4 *a1, s32 a2) {
    Vec4 t;
    f32 r;
    t = *a1;
    r = func_L01_00451700(a0, &t, a2);
    return __builtin_fabsf(r);
}
#endif
