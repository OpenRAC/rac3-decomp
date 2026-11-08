/* Near miss, ported from rac2-decomp's func_L00_00323F28 (cross-game near pair). NEAR: body shape right (r=func_00120884(a1); func_L39_00500600(a0,a1,r), floats not passed in retail) but frame is 0x30 with s0@0,s1@0x10,s1 moved before s0; ours 0x20; 10 diff; unexplained extra stack, 4 tries */
extern void *func_00120884(void *);
extern void func_L39_00500600(void *, void *, void *);

void func_L39_00500948(void *a0, void *a1) {
    void *r = func_00120884(a1);
    func_L39_00500600(a0, a1, r);
}
