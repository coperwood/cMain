int Model::nverts() const {
    return verts.size();
}

int Model::nfaces() const {
    return facet_vrt.size()/3;
}

vec3 Model::vert(const int i) const {
    return verts[i];
}

vec3 Model::vert(const int iface, const int nthvert) const {
    return verts[facet_vrt[iface*3+nthvert]];
}

void Model::load_texture(std::string filename, const std::string suffix, TGAImage &img) {
    size_t dot = filename.find_last_of(".");
    if (dot==std::string::npos) return;
    std::string texfile = filename.substr(0,dot) + suffix;
    std::cerr << "texture file " << texfile << " loading " << (img.read_tga_file(texfile.c_str()) ? "ok" : "failed") << std::endl;
}
//nice
vec3 Model::normal(const vec2 &uvf) const {
    TGAColor c = normalmap.get(uvf[0]*normalmap.width(), uvf[1]*normalmap.height());
    return vec3{(double)c[2],(double)c[1],(double)c[0]}*2./255. - vec3{1,1,1};
}
