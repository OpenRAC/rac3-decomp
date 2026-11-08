/* func_L39_004B40C8: near miss 4 diff (Sonnet w3, p2w1)
   file: src/levels/39_multiplayer_menu/L39_004B3230.c, 60 bytes
   delay slot fill: retail puts sh in jal delay, addiu a0 before; return 4 vs ld s0 order
*/
extern unsigned short func_L39_004B5938(int);
int func_L39_004B40C8(unsigned short *s){ s[0] = func_L39_004B5938(2); s[1] = func_L39_004B5938(5); return 4; }
