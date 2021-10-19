var nativeExtension = require("../");
var assert = require("assert");
const { KlondikeSolver } = require("..");

const solitaire =
  "042041044124023073111012123081104093031052051121094074061091083102043071132134113114131022103013062032101011014034054021112064092082133033072053084063024122";

const solveSolitaire = function (
  solver,
  drawCount,
  numThreads,
  maxClosedCount
) {
  solver.setDrawCount(drawCount);
  solver.resetGame();
  solver.solveMinimalMultithreaded(numThreads, maxClosedCount);
};

describe("native extension", function () {
  const solver = new KlondikeSolver();
  solver.loadSolitaire(solitaire);

  it(`Solitaire ${solitaire}, draw 1`, function (done) {
    solveSolitaire(solver, 1, 4, 5000000);
    const movesCount = solver.movesNormalizedCount();
    assert.equal(movesCount, 125);
    done();
  });

  it(`Solitaire ${solitaire}, draw 3`, function (done) {
    solveSolitaire(solver, 3, 4, 5000000);
    const movesCount = solver.movesNormalizedCount();
    assert.equal(movesCount, 109);
    done();
  });
});
