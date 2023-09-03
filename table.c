#include "table.h"
#include <stdio.h>

/* Denna funktion används för att initiera en ny ruta på ett angivet spelbräde. Rutan kan
 * antingen initieras med en bricka eller utan en bricka. För att rutan ska kunna initieras
 * med en bricka får inte player-pekaren peka på NULL.
 * För övrigt är funktionen deklaread som static då jag vill att den här funktionen bara ska vara
 * tillgänglig inom den här källkodfilen (samma sak med de andra funktionerna nedan som har deklarerats med static). */
static void init_table_square(table *t, const u_short row, const u_short column, const player *p)
{
	t->squares[row][column] = new_square(p != NULL ? create_piece(p) : NULL);
}

//Den här funktionen initierar ett spelbräde.
static void init_table(table *t, const player *p1, const player *p2)
{
	u_short row, column;
	const char P1_SYMBOL = get_uncrowned_piece_symbol(p1), P2_SYMBOL = get_uncrowned_piece_symbol(p2);

	//Denna array innehåller endast tecken och anger bara hur ett spelbräde ska se ut när ett nytt spel påbörjas.
	const char DEFAULT_SQUARES[TABLE_ROW_SIZE][TABLE_COLUMN_SIZE] =
	{{P1_SYMBOL, EMPTY, P1_SYMBOL, EMPTY, P1_SYMBOL, EMPTY, P1_SYMBOL, EMPTY},
	{EMPTY, P1_SYMBOL, EMPTY, P1_SYMBOL, EMPTY, P1_SYMBOL, EMPTY, P1_SYMBOL},
	{P1_SYMBOL, EMPTY, P1_SYMBOL, EMPTY, P1_SYMBOL, EMPTY, P1_SYMBOL, EMPTY},
	{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
	{EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
	{EMPTY, P2_SYMBOL, EMPTY, P2_SYMBOL, EMPTY, P2_SYMBOL, EMPTY, P2_SYMBOL},
	{P2_SYMBOL, EMPTY, P2_SYMBOL, EMPTY, P2_SYMBOL, EMPTY, P2_SYMBOL, EMPTY},
	{EMPTY, P2_SYMBOL, EMPTY, P2_SYMBOL, EMPTY, P2_SYMBOL, EMPTY, P2_SYMBOL}};

	//Initierar alla rutor på spelbrädet med hjälp av arrayen ovan som läses av.
	for(row = 0; row < TABLE_ROW_SIZE; row++)
		for(column = 0; column < TABLE_COLUMN_SIZE; column++)
			if(DEFAULT_SQUARES[row][column] == P1_SYMBOL)//Matchar tecknet spelare 1:s tecken? Då initieras denna ruta med en bricka som tillhör spelare 1.
				init_table_square(t, row, column, p1);
			else if(DEFAULT_SQUARES[row][column] == P2_SYMBOL)//Matchar tecknet spelare 2:s tecken? Då initieras denna ruta med en bricka som tillhör spelare 2.
				init_table_square(t, row, column, p2);
			else//Matchar tecknet varken spelare 1:s eller spelare 2:s tecken? Då initieras denna rutan som en tom ruta.
				init_table_square(t, row, column, NULL);
}

//Denna funktion tar bort alla brickor från ett spelbräde.
static void clean_table(table *t)
{
	u_short row, column;
	for(row = 0; row < TABLE_ROW_SIZE; row++)
		for(column = 0; column < TABLE_COLUMN_SIZE; column++)
			if(square_empty(get_table_square(t, row, column)))//Är rutan inte tom? Då ska dess bricka tas bort.
				remove_square_piece(&t->squares[row][column]);//Tar bort rutans bricka.
}

//Denna funktion skriver ut en horisontell linje.
static void print_horizontal_line()
{
	u_short column;
	for(column = 0; column < TABLE_COLUMN_SIZE; column++)
		printf("%s", column == 0 ? "  +---" : "+---");//Är det den första delen av linjen som skrivs ut? Då ska två mellanrum först skrivas ut för att ge plats åt radnumret.
	printf("+\n");
}

//Denna funktion skriver ut ett radnummer.
static void print_row_number(const u_short row)
{
	printf("%hu ", row + 1);
}

//Den här funktionen skriver ut en rads alla rutor.
static void print_squares(const table *t, const u_short row)
{
	u_short column;
	for(column = 0; column < TABLE_COLUMN_SIZE; column++)
		print_square(get_table_square(t, row, column));//Skriver ut ruta efter ruta.
	printf("|\n");
}

//Denna funktion skriver ut kolumnnummret för varje kolumn.
static void print_column_number()
{
	u_short column;
	for(column = 0; column < TABLE_COLUMN_SIZE; column++)
		printf("%s%hu%c", column == 0 ? "    " : "  ", column + 1, ' ');//Är det det första kolumnnumret som skrivs ut ska två extra mellanrum först skrivas ut.
	printf("\n\n");
}

//Den här funktionen returnerar ett initierat spelbräde.
table new_table(const player *p1, const player *p2)
{
	table t;
 	init_table(&t, p1, p2);
	return t;
}

//Den här funktionen returnerar en angiven ruta.
const square *get_table_square(const table *t, const u_short row, const u_short column)
{
	return &t->squares[row][column];
}

//Vill man påbörja ett nytt spel efter att en spelare har vunnit så är det den här funktionen som man ska kalla på.
void reset_table(table *t, const player *p1, const player *p2)
{
	clean_table(t);//Rensar först spelbrädet.
 	init_table(t, p1, p2);//Initierar det sedan med nya brickor.
}

//Den här funktionen skriver ut hela spelbrädet (inklusive rad- och kolumnnumrering).
void print_table(const table *t)
{
	u_short row;
	for(row = 0; row < TABLE_ROW_SIZE; row++){//Skriver ut rad efter rad. Varje rad består av en horisontell linje, ett radnummer och ett visst antal rutor.
		print_horizontal_line();//Skriver först ut radens horisontella linje.
		print_row_number(row);//Sedan dess radnummer.
		print_squares(t, row);//Sist dess rutor.
	}
	//Skriver allra sist ut en extra horisontell linje och numreringen för alla kolumner.
	print_horizontal_line();
	print_column_number();
}
