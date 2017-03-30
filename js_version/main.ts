namespace mbx
{
  export abstract class NodeVisitor
  {
    public reset( ): void
    {
    }
    public traverse(node: Node): void
    {
      this.reset( );
      node.accept( this );
    }
    public visitNode(node: Node): void
    {
      // Do nothing
    }
    public visitGroup( group: Group ): void
    {
      let that = this;
      group.forEach(function(n: Node)
      {
        n.accept(that);
      });
    }
  }
  export class ApplyVisitor extends NodeVisitor
  {
    constructor( callback: Function )
    {
      super( );
      this._callback = callback;
    }
    public visitNode( n: Node )
    {
      this._callback( n );
    }
    public visitGroup( g: Group )
    {
      this._callback( g );
      super.visitGroup( g );
    }
    protected _callback: Function;
  }
  export class PrintNameVisitor extends ApplyVisitor
  {
    constructor( )
    {
      super(function(n: Node)
      {
        console.log( n.name );
      });
    }
  }
  export class Node
  {
    constructor( name: string )
    {
        this._name = name;
        this._parent = null;
    }
    public get name(): string { return this._name; };
    public set name(n: string) { this._name = n; };

    protected _parent: Node;
    protected _name: string;

    public perform(visitor: NodeVisitor): void
    {
      visitor.traverse( this );
    }
    public accept(visitor: NodeVisitor): void
    {
      visitor.visitNode( this );
    }
    public hasParent( ): boolean
    {
      return this._parent != null;
    }
    public get parent( ): Node
    {
      return this._parent;
    }
    public set parent(p: Node)
    {
      this._parent = p;
    }
  }
  export class Group extends Node
  {
    constructor( name: string )
    {
      super( name );
    }
    public hasNodes( ): boolean
    {
      return this._children.length != 0;
    }
    public numChildren( ): number
    {
      return this._children.length;
    }
    public addChild(node: Node)
    {
      if ( node.parent == this )
      {
        return;
      }
      if ( node.parent != null )
      {
        throw "HasParentException";
      }
      node.parent = this;
      this._children.push( node );
    }
    public removeChild(node: Node)
    {
      // TODO
    }
    public removeChildren( )
    {
      // TODO
    }
    public nodeAt(idx: number): Node
    {
      return this._children[ idx ];
    }
    public forEach(callback: Function)
    {
      this._children.forEach(function(n: Node){
        callback( n );
      });
    }
    public accept(visitor: NodeVisitor)
    {
      visitor.visitGroup(this);
    }
    protected _children: Array<Node> = new Array<Node>( );
  }
  export class Switch extends Group
  {
    constructor( name: string )
    {
      super( name );
      this._currentIdx = 0;
    }

    public forEach(callback: Function)
    {
      if (!this.hasNodes( ))
      {
        return;
      }
      let current: Node = this.nodeAt( this._currentIdx );
      if ( current != null )
      {
        callback( current );
      }
    }

    public selectNextNode( ): void
    {
      if (!this.hasNodes( ))
      {
        return;
      }
      this._currentIdx = ( this._currentIdx + 1 ) % this.numChildren( );
    }
    public selectPrevNode( ): void
    {
      if ( !this.hasNodes( ) )
      {
        return;
      }
      let nChildren: number = this.numChildren( );
      this._currentIdx = ( this._currentIdx + nChildren - 1 ) % nChildren;
    }

    public currentNode( ): Node
    {
      return this.nodeAt( this._currentIdx );
    }

    public get currentNodeIndex( ): number
    {
      return this._currentIdx;
    }

    public set currentNodeIndex( idx: number )
    {
      this._currentIdx = idx;
    }

    private _currentIdx: number;
  }
}

let scene = new mbx.Group("scene");
let leftNode = new mbx.Node("leftNode");
let centerSwitch = new mbx.Switch("centerSwitch");
let rightNode = new mbx.Node("rightNode");

scene.addChild(leftNode);
scene.addChild(centerSwitch);
scene.addChild(rightNode);

let firstNodeSwitch = new mbx.Node( "firstNodeSwitch" );
let secondNodeSwitch = new mbx.Group( "secondNodeSwitch" );
secondNodeSwitch.addChild( new mbx.Node( "firstSecondNodeSwitch" ) );
let thirdNodeSwitch = new mbx.Node( "thirdNodeSwitch" );

centerSwitch.addChild( firstNodeSwitch );
centerSwitch.addChild( secondNodeSwitch );
centerSwitch.addChild( thirdNodeSwitch );

  /*leftNode->addComponent( new MeshRenderer( 3 ) );
  secondNodeSwitch->addComponent( new MeshRenderer( 12 ) );
  //rightNode->addComponent( new MeshRenderer( 2 ) );*/
//centerSwitch.currentNodeIndex = 1;

let v = new mbx.PrintNameVisitor( );
v.traverse( scene );

centerSwitch.currentNodeIndex = 1;
v.traverse( scene );
