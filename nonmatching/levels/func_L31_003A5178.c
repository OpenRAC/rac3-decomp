/* func_L31_003A5178: p2 near miss (w8), 2 diff. Retail loads the gp float (lwc1 f1,0x20b0(gp)) before abs.s f0; we emit abs.s first.
   Tried: ternary/if/local-order variants; ps2as worse. */
extern float D_L31_001DE960;
extern float func_L31_003A5B00(void *);
extern float func_0038DB00(float, float);
extern float fabsf(float);
int func_L31_003A5178(unsigned char *m) { float r = func_L31_003A5B00(m); float d = func_0038DB00(*(float *)(m + 0xF8), r); if (fabsf(d) > D_L31_001DE960) return 0; return 1; }
