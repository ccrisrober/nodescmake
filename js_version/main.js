var mbx;
(function (mbx) {
    class NodeVisitor {
        reset() {
        }
        traverse(node) {
            this.reset();
            node.accept(this);
        }
        visitNode(node) {
            // Do nothing
        }
        visitGroup(group) {
            let that = this;
            group.forEach(function (n) {
                n.accept(that);
            });
        }
    }
    mbx.NodeVisitor = NodeVisitor;
    class ApplyVisitor extends NodeVisitor {
        constructor(callback) {
            super();
            this._callback = callback;
        }
        visitNode(n) {
            this._callback(n);
        }
        visitGroup(g) {
            this._callback(g);
            super.visitGroup(g);
        }
    }
    mbx.ApplyVisitor = ApplyVisitor;
    class PrintNameVisitor extends ApplyVisitor {
        constructor() {
            super(function (n) {
                console.log(n.name);
            });
        }
    }
    mbx.PrintNameVisitor = PrintNameVisitor;
    class Node {
        constructor(name) {
            this._name = name;
            this._parent = null;
        }
        get name() { return this._name; }
        ;
        set name(n) { this._name = n; }
        ;
        perform(visitor) {
            visitor.traverse(this);
        }
        accept(visitor) {
            visitor.visitNode(this);
        }
        hasParent() {
            return this._parent != null;
        }
        get parent() {
            return this._parent;
        }
        set parent(p) {
            this._parent = p;
        }
    }
    mbx.Node = Node;
    class Group extends Node {
        constructor(name) {
            super(name);
            this._children = new Array();
        }
        hasNodes() {
            return this._children.length != 0;
        }
        numChildren() {
            return this._children.length;
        }
        addChild(node) {
            if (node.parent == this) {
                return;
            }
            if (node.parent != null) {
                throw "HasParentException";
            }
            node.parent = this;
            this._children.push(node);
        }
        removeChild(node) {
            // TODO
        }
        removeChildren() {
            // TODO
        }
        nodeAt(idx) {
            return this._children[idx];
        }
        forEach(callback) {
            this._children.forEach(function (n) {
                callback(n);
            });
        }
        accept(visitor) {
            visitor.visitGroup(this);
        }
    }
    mbx.Group = Group;
    class Switch extends Group {
        constructor(name) {
            super(name);
            this._currentIdx = 0;
        }
        forEach(callback) {
            if (!this.hasNodes()) {
                return;
            }
            let current = this.nodeAt(this._currentIdx);
            if (current != null) {
                callback(current);
            }
        }
        selectNextNode() {
            if (!this.hasNodes()) {
                return;
            }
            this._currentIdx = (this._currentIdx + 1) % this.numChildren();
        }
        selectPrevNode() {
            if (!this.hasNodes()) {
                return;
            }
            let nChildren = this.numChildren();
            this._currentIdx = (this._currentIdx + nChildren - 1) % nChildren;
        }
        currentNode() {
            return this.nodeAt(this._currentIdx);
        }
        get currentNodeIndex() {
            return this._currentIdx;
        }
        set currentNodeIndex(idx) {
            this._currentIdx = idx;
        }
    }
    mbx.Switch = Switch;
})(mbx || (mbx = {}));
let scene = new mbx.Group("scene");
let leftNode = new mbx.Node("leftNode");
let centerSwitch = new mbx.Switch("centerSwitch");
let rightNode = new mbx.Node("rightNode");
scene.addChild(leftNode);
scene.addChild(centerSwitch);
scene.addChild(rightNode);
let firstNodeSwitch = new mbx.Node("firstNodeSwitch");
let secondNodeSwitch = new mbx.Group("secondNodeSwitch");
secondNodeSwitch.addChild(new mbx.Node("firstSecondNodeSwitch"));
let thirdNodeSwitch = new mbx.Node("thirdNodeSwitch");
centerSwitch.addChild(firstNodeSwitch);
centerSwitch.addChild(secondNodeSwitch);
centerSwitch.addChild(thirdNodeSwitch);
/*leftNode->addComponent( new MeshRenderer( 3 ) );
secondNodeSwitch->addComponent( new MeshRenderer( 12 ) );
//rightNode->addComponent( new MeshRenderer( 2 ) );*/
//centerSwitch.currentNodeIndex = 1;
let v = new mbx.PrintNameVisitor();
v.traverse(scene);
centerSwitch.currentNodeIndex = 1;
v.traverse(scene);
