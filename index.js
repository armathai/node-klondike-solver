const klondikeSolverNativeExtension = require("bindings")(
  "Klondike-Solver-NativeExtension"
);

function _classCallCheck(instance, Constructor) {
  if (!(instance instanceof Constructor)) {
    throw new TypeError("Cannot call a class as a function");
  }
}

function _defineProperties(target, props) {
  for (var i = 0; i < props.length; i++) {
    var descriptor = props[i];
    descriptor.enumerable = descriptor.enumerable || false;
    descriptor.configurable = true;
    if ("value" in descriptor) descriptor.writable = true;
    Object.defineProperty(target, descriptor.key, descriptor);
  }
}

function _createClass(Constructor, protoProps, staticProps) {
  if (protoProps) _defineProperties(Constructor.prototype, protoProps);
  if (staticProps) _defineProperties(Constructor, staticProps);
  return Constructor;
}

const KlondikeSolver = /*#__PURE__*/ (function () {
  function KlondikeSolver() {
    _classCallCheck(this, KlondikeSolver);

    this.wrapper = new klondikeSolverNativeExtension.SolitaireWrap();
    this.wrapper.initialize();
  }

  _createClass(KlondikeSolver, [
    {
      key: "resetGame",
      value: function resetGame() {
        this.wrapper.resetGame();
      },
    },
    {
      key: "setDrawCount",
      value: function setDrawCount(drawCount) {
        this.wrapper.setDrawCount(drawCount);
      },
    },
    {
      key: "loadSolitaire",
      value: function loadSolitaire(cardSet) {
        return this.wrapper.loadSolitaire(cardSet);
      },
    },
    {
      key: "getSolitaire",
      value: function getSolitaire() {
        return this.wrapper.getSolitaire();
      },
    },
    {
      key: "solveMinimal",
      value: function solveMinimal(maxClosedCount) {
        return this.wrapper.solveMinimal(maxClosedCount);
      },
    },
    {
      key: "solveMinimalMultithreaded",
      value: function solveMinimalMultithreaded(numThreads, maxClosedCount) {
        return this.wrapper.solveMinimalMultithreaded(
          numThreads,
          maxClosedCount
        );
      },
    },
    {
      key: "shuffle",
      value: function shuffle() {
        var dealNumber =
          arguments.length > 0 && arguments[0] !== undefined
            ? arguments[0]
            : -1;
        return this.wrapper.shuffle(dealNumber);
      },
    },
    {
      key: "gameDiagram",
      value: function gameDiagram() {
        return this.wrapper.gameDiagram();
      },
    },
    {
      key: "gameDiagramPysol",
      value: function gameDiagramPysol() {
        return this.wrapper.gameDiagramPysol();
      },
    },
    {
      key: "movesNormalizedCount",
      value: function movesNormalizedCount() {
        return this.wrapper.movesMadeNormalizedCount();
      },
    },
    {
      key: "movesCount",
      value: function movesCount() {
        return this.wrapper.movesMadeCount();
      },
    },
    {
      key: "moves",
      value: function moves() {
        return this.wrapper.movesMade();
      },
    },
  ]);

  return KlondikeSolver;
})();

const SolveResult = Object.freeze({
  CouldNotComplete: -2,
  SolvedMayNotBeMinimal: -1,
  Impossible: 0,
  SolvedMinimal: 1,
});

exports.KlondikeSolver = KlondikeSolver;
exports.SolveResult = SolveResult;
