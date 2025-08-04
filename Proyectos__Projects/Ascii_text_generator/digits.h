/*
#author: @lfvcodes
https://github.com/lfvcodes/CPP-Projects
*/

// Mapa de caracteres ASCII para cada letra (mayúsculas y minúsculas)
#include <string>
#include <vector>
#include <map>
#include <cctype> // Para toupper()

using namespace std;

void initAsciiArt(map<char, vector<string> > &asciiArt)
{
  vector<string> A;
  A.push_back("  AA  ");
  A.push_back(" A  A ");
  A.push_back("AAAAA ");
  A.push_back("A    A");
  A.push_back("A    A");
  asciiArt['A'] = A;

  vector<string> B;
  B.push_back("BBBB  ");
  B.push_back("B   B ");
  B.push_back("BBBB  ");
  B.push_back("B   B ");
  B.push_back("BBBB  ");
  asciiArt['B'] = B;

  vector<string> C;
  C.push_back(" CCCC ");
  C.push_back("C     ");
  C.push_back("C     ");
  C.push_back("C     ");
  C.push_back(" CCCC ");
  asciiArt['C'] = C;

  vector<string> D;
  D.push_back("DDDD  ");
  D.push_back("D   D ");
  D.push_back("D   D ");
  D.push_back("D   D ");
  D.push_back("DDDD  ");
  asciiArt['D'] = D;

  vector<string> E;
  E.push_back("EEEEE ");
  E.push_back("E     ");
  E.push_back("EEEEE ");
  E.push_back("E     ");
  E.push_back("EEEEE ");
  asciiArt['E'] = E;

  vector<string> F;
  F.push_back("FFFFF ");
  F.push_back("F     ");
  F.push_back("FFFFF ");
  F.push_back("F     ");
  F.push_back("F     ");
  asciiArt['F'] = F;

  vector<string> G;
  G.push_back(" GGGG ");
  G.push_back("G     ");
  G.push_back("G  GG ");
  G.push_back("G   G ");
  G.push_back(" GGGG ");
  asciiArt['G'] = G;

  vector<string> H;
  H.push_back("H   H ");
  H.push_back("H   H ");
  H.push_back("HHHHH ");
  H.push_back("H   H ");
  H.push_back("H   H ");
  asciiArt['H'] = H;

  vector<string> I;
  I.push_back("IIIII ");
  I.push_back("  I   ");
  I.push_back("  I   ");
  I.push_back("  I   ");
  I.push_back("IIIII ");
  asciiArt['I'] = I;

  vector<string> J;
  J.push_back("    J ");
  J.push_back("    J ");
  J.push_back("    J ");
  J.push_back("J   J ");
  J.push_back(" JJJ  ");
  asciiArt['J'] = J;

  vector<string> K;
  K.push_back("K   K ");
  K.push_back("K  K  ");
  K.push_back("KKK   ");
  K.push_back("K  K  ");
  K.push_back("K   K ");
  asciiArt['K'] = K;

  vector<string> L;
  L.push_back("L     ");
  L.push_back("L     ");
  L.push_back("L     ");
  L.push_back("L     ");
  L.push_back("LLLLL ");
  asciiArt['L'] = L;

  vector<string> M;
  M.push_back("M   M ");
  M.push_back("MM MM ");
  M.push_back("M M M ");
  M.push_back("M   M ");
  M.push_back("M   M ");
  asciiArt['M'] = M;

  vector<string> N;
  N.push_back("N   N ");
  N.push_back("NN  N ");
  N.push_back("N N N ");
  N.push_back("N  NN ");
  N.push_back("N   N ");
  asciiArt['N'] = N;

  vector<string> O;
  O.push_back(" OOO  ");
  O.push_back("O   O ");
  O.push_back("O   O ");
  O.push_back("O   O ");
  O.push_back(" OOO  ");
  asciiArt['O'] = O;

  vector<string> P;
  P.push_back("PPPP  ");
  P.push_back("P   P ");
  P.push_back("PPPP  ");
  P.push_back("P     ");
  P.push_back("P     ");
  asciiArt['P'] = P;

  vector<string> Q;
  Q.push_back(" QQQ  ");
  Q.push_back("Q   Q ");
  Q.push_back("Q   Q ");
  Q.push_back("Q  QQ ");
  Q.push_back(" QQQQ ");
  asciiArt['Q'] = Q;

  vector<string> R;
  R.push_back("RRRR  ");
  R.push_back("R   R ");
  R.push_back("RRRR  ");
  R.push_back("R  R  ");
  R.push_back("R   R ");
  asciiArt['R'] = R;

  vector<string> S;
  S.push_back(" SSS  ");
  S.push_back("S     ");
  S.push_back(" SSS  ");
  S.push_back("    S ");
  S.push_back("SSSS  ");
  asciiArt['S'] = S;

  vector<string> T;
  T.push_back("TTTTT ");
  T.push_back("  T   ");
  T.push_back("  T   ");
  T.push_back("  T   ");
  T.push_back("  T   ");
  asciiArt['T'] = T;

  vector<string> U;
  U.push_back("U   U ");
  U.push_back("U   U ");
  U.push_back("U   U ");
  U.push_back("U   U ");
  U.push_back(" UUU  ");
  asciiArt['U'] = U;

  vector<string> V;
  V.push_back("V   V ");
  V.push_back("V   V ");
  V.push_back("V   V ");
  V.push_back(" V V  ");
  V.push_back("  V   ");
  asciiArt['V'] = V;

  vector<string> W;
  W.push_back("W   W ");
  W.push_back("W   W ");
  W.push_back("W W W ");
  W.push_back("WW WW ");
  W.push_back("W   W ");
  asciiArt['W'] = W;

  vector<string> X;
  X.push_back("X   X ");
  X.push_back(" X X  ");
  X.push_back("  X   ");
  X.push_back(" X X  ");
  X.push_back("X   X ");
  asciiArt['X'] = X;

  vector<string> Y;
  Y.push_back("Y   Y ");
  Y.push_back(" Y Y  ");
  Y.push_back("  Y   ");
  Y.push_back("  Y   ");
  Y.push_back("  Y   ");
  asciiArt['Y'] = Y;

  vector<string> Z;
  Z.push_back("ZZZZZ ");
  Z.push_back("   Z  ");
  Z.push_back("  Z   ");
  Z.push_back(" Z    ");
  Z.push_back("ZZZZZ ");
  asciiArt['Z'] = Z;

  // Espacio
  vector<string> space;
  space.push_back("      ");
  space.push_back("      ");
  space.push_back("      ");
  space.push_back("      ");
  space.push_back("      ");
  asciiArt[' '] = space;

  // Letras min�sculas
  vector<string> a;
  a.push_back("      ");
  a.push_back(" aaa  ");
  a.push_back("a   a ");
  a.push_back("a   a ");
  a.push_back(" aaa a");
  asciiArt['a'] = a;

  vector<string> b;
  b.push_back("b     ");
  b.push_back("b     ");
  b.push_back("bbbb  ");
  b.push_back("b   b ");
  b.push_back("bbbb  ");
  asciiArt['b'] = b;

  vector<string> c;
  c.push_back("      ");
  c.push_back(" cccc ");
  c.push_back("c     ");
  c.push_back("c     ");
  c.push_back(" cccc ");
  asciiArt['c'] = c;

  vector<string> d;
  d.push_back("    d ");
  d.push_back("    d ");
  d.push_back(" dddd ");
  d.push_back("d   d ");
  d.push_back(" dddd ");
  asciiArt['d'] = d;

  vector<string> e;
  e.push_back("      ");
  e.push_back(" eeee ");
  e.push_back("ee  e ");
  e.push_back("eeeee ");
  e.push_back(" eeee ");
  asciiArt['e'] = e;

  vector<string> f;
  f.push_back("  fff ");
  f.push_back(" f    ");
  f.push_back("ffff  ");
  f.push_back(" f    ");
  f.push_back(" f    ");
  asciiArt['f'] = f;

  vector<string> g;
  g.push_back("      ");
  g.push_back(" gggg ");
  g.push_back("g   g ");
  g.push_back(" gggg ");
  g.push_back("    g ");
  g.push_back(" ggg  ");
  asciiArt['g'] = g;

  vector<string> h;
  h.push_back("h     ");
  h.push_back("h     ");
  h.push_back("hhhh  ");
  h.push_back("h   h ");
  h.push_back("h   h ");
  asciiArt['h'] = h;

  vector<string> i;
  i.push_back("i ");
  i.push_back("  ");
  i.push_back("i ");
  i.push_back("i ");
  i.push_back("i ");
  asciiArt['i'] = i;

  vector<string> j;
  j.push_back("  j ");
  j.push_back("    ");
  j.push_back("  j ");
  j.push_back("  j ");
  j.push_back("jjj ");
  asciiArt['j'] = j;

  vector<string> k;
  k.push_back("k    ");
  k.push_back("k    ");
  k.push_back("k  k ");
  k.push_back("kk   ");
  k.push_back("k  k ");
  asciiArt['k'] = k;

  vector<string> l;
  l.push_back("l ");
  l.push_back("l ");
  l.push_back("l ");
  l.push_back("l ");
  l.push_back("l ");
  asciiArt['l'] = l;

  vector<string> m;
  m.push_back("      ");
  m.push_back("mmmmm ");
  m.push_back("m m m ");
  m.push_back("m m m ");
  m.push_back("m m m ");
  asciiArt['m'] = m;

  vector<string> n;
  n.push_back("      ");
  n.push_back("nnnn  ");
  n.push_back("n   n ");
  n.push_back("n   n ");
  n.push_back("n   n ");
  asciiArt['n'] = n;

  vector<string> o;
  o.push_back("      ");
  o.push_back(" ooo  ");
  o.push_back("o   o ");
  o.push_back("o   o ");
  o.push_back(" ooo  ");
  asciiArt['o'] = o;

  vector<string> p;
  p.push_back("      ");
  p.push_back("pppp  ");
  p.push_back("p   p ");
  p.push_back("pppp  ");
  p.push_back("p     ");
  asciiArt['p'] = p;

  vector<string> q;
  q.push_back("      ");
  q.push_back(" qqqq ");
  q.push_back("q   q ");
  q.push_back(" qqqq ");
  q.push_back("    q ");
  asciiArt['q'] = q;

  vector<string> r;
  r.push_back("      ");
  r.push_back("rrrr  ");
  r.push_back("r     ");
  r.push_back("r     ");
  r.push_back("r     ");
  asciiArt['r'] = r;

  vector<string> s;
  s.push_back("      ");
  s.push_back(" ssss ");
  s.push_back("s     ");
  s.push_back(" ssss ");
  s.push_back("    s ");
  s.push_back("ssss  ");
  asciiArt['s'] = s;

  vector<string> t;
  t.push_back(" t   ");
  t.push_back("tttt ");
  t.push_back(" t   ");
  t.push_back(" t   ");
  t.push_back(" ttt ");
  asciiArt['t'] = t;

  vector<string> u;
  u.push_back("      ");
  u.push_back("u   u ");
  u.push_back("u   u ");
  u.push_back("u   u ");
  u.push_back(" uuuu ");
  asciiArt['u'] = u;

  vector<string> v;
  v.push_back("      ");
  v.push_back("v   v ");
  v.push_back("v   v ");
  v.push_back(" v v  ");
  v.push_back("  v   ");
  asciiArt['v'] = v;

  vector<string> w;
  w.push_back("      ");
  w.push_back("w   w ");
  w.push_back("w w w ");
  w.push_back("ww ww ");
  w.push_back("w   w ");
  asciiArt['w'] = w;

  vector<string> x;
  x.push_back("      ");
  x.push_back("x   x ");
  x.push_back(" x x  ");
  x.push_back(" x x  ");
  x.push_back("x   x ");
  asciiArt['x'] = x;

  vector<string> y;
  y.push_back("      ");
  y.push_back("y   y ");
  y.push_back(" yyyy ");
  y.push_back("    y ");
  y.push_back(" yyy  ");
  asciiArt['y'] = y;

  vector<string> z;
  z.push_back("      ");
  z.push_back("zzzzz ");
  z.push_back("   z  ");
  z.push_back(" z    ");
  z.push_back("zzzzz ");
  asciiArt['z'] = z;

  // Agregar esto al final de tu función initAsciiArt, antes de la llave de cierre

  // Números 0-9
  vector<string> zero;
  zero.push_back(" 0000 ");
  zero.push_back("0    0");
  zero.push_back("0    0");
  zero.push_back("0    0");
  zero.push_back(" 0000 ");
  asciiArt['0'] = zero;

  vector<string> one;
  one.push_back("  11  ");
  one.push_back(" 111  ");
  one.push_back("  11  ");
  one.push_back("  11  ");
  one.push_back(" 1111 ");
  asciiArt['1'] = one;

  vector<string> two;
  two.push_back(" 2222 ");
  two.push_back("2    2");
  two.push_back("   22 ");
  two.push_back(" 22   ");
  two.push_back("222222");
  asciiArt['2'] = two;

  vector<string> three;
  three.push_back(" 3333 ");
  three.push_back("3    3");
  three.push_back("   33 ");
  three.push_back("3    3");
  three.push_back(" 3333 ");
  asciiArt['3'] = three;

  vector<string> four;
  four.push_back("4   4 ");
  four.push_back("4   4 ");
  four.push_back("44444 ");
  four.push_back("    4 ");
  four.push_back("    4 ");
  asciiArt['4'] = four;

  vector<string> five;
  five.push_back("55555 ");
  five.push_back("5     ");
  five.push_back("5555  ");
  five.push_back("    5 ");
  five.push_back("5555  ");
  asciiArt['5'] = five;

  vector<string> six;
  six.push_back(" 6666 ");
  six.push_back("6     ");
  six.push_back("6666  ");
  six.push_back("6    6");
  six.push_back(" 6666 ");
  asciiArt['6'] = six;

  vector<string> seven;
  seven.push_back("77777 ");
  seven.push_back("    7 ");
  seven.push_back("   7  ");
  seven.push_back("  7   ");
  seven.push_back(" 7    ");
  asciiArt['7'] = seven;

  vector<string> eight;
  eight.push_back(" 8888 ");
  eight.push_back("8    8");
  eight.push_back(" 8888 ");
  eight.push_back("8    8");
  eight.push_back(" 8888 ");
  asciiArt['8'] = eight;

  vector<string> nine;
  nine.push_back(" 9999 ");
  nine.push_back("9    9");
  nine.push_back(" 9999 ");
  nine.push_back("    9 ");
  nine.push_back(" 999  ");
  asciiArt['9'] = nine;
}
