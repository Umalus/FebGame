#version 330 core

out vec4 FragColor;
uniform vec3 uDiffuseColor;
uniform vec3 uSpecularColor;
uniform vec3 uEmissiveColor;

void main() {
    // 3‚Â‚ÌF‚ğ¬‚º‚Äg‚¤‚±‚Æ‚ÅÅ“K‰»‚³‚ê‚È‚¢
    vec3 color = uDiffuseColor * 0.6 + uSpecularColor * 0.3 + uEmissiveColor * 0.1;
    FragColor = vec4(color, 1.0);
}
