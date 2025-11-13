using Godot;
using System;

public abstract partial class Grid : Node
{
	protected abstract Vector2I ChunkBasisX { get; }
	protected abstract Vector2I ChunkBasisY { get; }
	
	// Plan to add 3D support too
	// Add actual tile maps later, for now just make a blank one
	public void AddTileMap(Vector2I position)
	{
		TileMapLayer proto = new TileMapLayer();
		proto.Name = TranslateToChunkName(position);
		AddChild(proto);
	}

	public void DeleteTileMap(Vector2I position)
	{
		GetNode(TranslateToChunkName(position)).QueueFree();
	}

	private string TranslateToChunkName(Vector2I position)
	{
		return $"{position.X}_{position.Y}";
	}
	
	// Called when the node enters the scene tree for the first time.
	public override void _Ready()
	{
		AddTileMap(Vector2I.Zero);
	}
}
