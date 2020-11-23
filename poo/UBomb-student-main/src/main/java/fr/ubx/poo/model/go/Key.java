package fr.ubx.poo.model.go;

import fr.ubx.poo.game.Direction;
import fr.ubx.poo.game.Game;
import fr.ubx.poo.game.Position;
import fr.ubx.poo.model.Movable;
//TODO Faire interaction
public class Key extends GameObject implements Movable {

    public Key(Game game, Position position){ super(game, position);}

    @Override
    public String toString() { return "Key";}

    @Override
    public void doMove(Direction direction) {}

    @Override
    public boolean canMove(Direction direction) {return false;}
}