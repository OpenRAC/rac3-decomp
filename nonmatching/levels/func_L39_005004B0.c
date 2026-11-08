/* Near miss, ported from rac2-decomp's func_L00_00323F28 (cross-game near pair). NEAR: body/registers now right (120884 returns ptr used as a2, args a1,a,b,c); only frame differs: retail 0x30 with s0@0,s1@0x10,ra@0x20 vs ours 0x20 (same unexplained 16-byte save spacing as 005057D0) */
extern void *func_00120884(void *, float, float, float);
extern void func_L39_00500198(void *, void *, void *);

void func_L39_005004B0(void *a0, void *a1, float a, float b, float c) {
    func_L39_00500198(a0, a1, func_00120884(a1, a, b, c));
}
