/* functional: high. Writes a uniform scale matrix: rows (s,0,0,0),(0,s,0,0),(0,0,s,0) and the last row (0,0,0,1.0f), which is the jr delay slot sqc2 split off as func_0038D304 (boundary split). Exact: no arithmetic beyond 0*x+s. */
void func_0038D2D0(f32 *out, f32 s) {
    out[0] = s;    out[1] = 0.0f; out[2] = 0.0f;  out[3] = 0.0f;
    out[4] = 0.0f; out[5] = s;    out[6] = 0.0f;  out[7] = 0.0f;
    out[8] = 0.0f; out[9] = 0.0f; out[10] = s;    out[11] = 0.0f;
    out[12] = 0.0f; out[13] = 0.0f; out[14] = 0.0f; out[15] = 1.0f;
}
