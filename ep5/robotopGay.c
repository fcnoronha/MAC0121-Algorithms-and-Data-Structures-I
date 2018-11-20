/*

 EP05 - MAC0121
 
 Carolina Marques Senra - 10737101
 Felipe Castro de Noronha - 10737032

*/

#include "robot_fight.h"

void prepareGame(Grid *grid, Position pos, int turnCount)
{
	setName("Robotop gay");
	// O legal é não planejar
}


Action processTurn(Grid *grid, Position pos, int turnsLeft)
{
	// Nosso robô é pacífico então ele não atira 
	if (grid->map[pos.x][pos.y].isControlPoint) // Estou no control point e não vou sair
		return STAND;
	
	// Tamanho do nosso mapa
	int m = grid->m, n = grid->n;
	// Nosso robô
	Robot *r = &grid->map[pos.x][pos.y].object.robot;	
	// Casa imediatamente a frente do nosso robô
	Position s = getNeighbor(pos, r->dir);

	// Confere se pode andar e se a casa para onde eu quero andar está vazia
	if ((s.x >= 0 && s.x < m && s.y >= 0 && s.y < n) && (grid->map[s.x][s.y].type == NONE))
		return WALK;
	
	// Em utimo caso, vira para a esquerda
	return TURN_LEFT;
}