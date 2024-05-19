void draw_straightedge_polygon(pen outline, pen fill_color, pair[] vertices){
    int sz = vertices.length;
    pair root = vertices[0];
    for (int i=0; i<sz; ++i){
        pair P1 = vertices[i];
        pair P2 = vertices[(i+1)%sz];
        draw(P1 -- P2, outline);
        fill(root -- P1 -- P2 -- cycle, fill_color);
    }
}
void newbasispoint(pair P1, pair P2, real shootpoint_P1, real )
void draw_smoothed_polygon(pen outline, pen fill_color, pair[] vertices){
    int sz = vertices.length;
    pair root = vertices[0];
    for (int i=0; i<sz; ++i){
        pair P1 = vertices[i];
        pair P2 = vertices[(i+1)%sz];
        draw(root .. P1 .. P2 -- cycle, outline);
    }
    for (int i=0; i<sz; ++i){
        pair P1 = vertices[i];
        pair P2 = vertices[(i+1)%sz];
        fill(root .. P1 .. P2 -- cycle, fill_color);
    }
}
