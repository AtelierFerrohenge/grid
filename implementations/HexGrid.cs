using Godot;
using System;

[GlobalClass]
public partial class HexGrid : Grid
{
	[Export]
	private int _chunkRadius { get; set; }

	private int _chunkDiameter => 2 * _chunkRadius + 1;
	
	protected override Vector2I ChunkBasisX => new Vector2I(_chunkDiameter, -_chunkRadius);
	protected override Vector2I ChunkBasisY => new Vector2I(_chunkRadius, _chunkRadius + 1);
}
