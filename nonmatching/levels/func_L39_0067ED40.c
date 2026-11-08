/* func_L39_0067ED40: p2 near miss (w8), 3 diff (rac2 twin func_002D4E10 was wrong; body re-derived from asm).
   Retail: lui a1; lw a1,D; move a0,v0 before jal; we emit move a0,v0 first then lw into a1 (schedule order only).
   Tried: r local, direct nested call, sized/unsized D. */
extern int D_001A5CD0[];
extern int D_L39_0024D170[];
extern int func_001917B8(int);
extern void func_00191640(void);
extern int func_00126150(void);
extern void func_001260F0(int, int);

void func_L39_0067ED40(void) {
    int *p = D_001A5CD0;
    int r;
    func_001917B8(p[4]);
    p[4] = -1;
    func_00191640();
    r = func_00126150();
    func_001260F0(r, D_L39_0024D170[0]);
}
