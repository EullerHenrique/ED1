
typedef struct Tmat2d Tmat2d;

Tmat2d *criarmat(int NLIN,int NCOL);
int prencher(Tmat2d *mat, int maximo);

int escrever_elem(Tmat2d *mat, int NLIN, int NCOL, double valor);
int acessa_elem(Tmat2d *mat, int NLIN, int NCOL, double *valor);

int somar(Tmat2d *mat, Tmat2d *mat2, Tmat2d *mat3);

int multiplicar(Tmat2d *mat, Tmat2d *mat2, Tmat2d *mat3);
int multiplica_escalar(Tmat2d *mat, Tmat2d *mat3, int x);

double traco(Tmat2d *mat, double *soma_diagonal);

double *soma_linha(Tmat2d *mat);
double *soma_coluna(Tmat2d *mat);

int libera(Tmat2d *mat);

