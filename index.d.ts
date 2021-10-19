declare enum SolveResult {
  CouldNotComplete = -2,
  SolvedMayNotBeMinimal = -1,
  Impossible = 0,
  SolvedMinimal = 1,
}

declare class KlondikeSolver {
  constructor();
  resetGame(): void;
  setDrawCount(drawCount: number): void;
  loadSolitaire(cardSet: string): void;
  getSolitaire(): string;
  solveMinimal(maxClosedCount: number): SolveResult;
  solveMinimalMultithreaded(
    numThreads: number,
    maxClosedCount: number
  ): SolveResult;
  shuffle(dealNumber: number): number;
  gameDiagram(): string;
  gameDiagramPysol(): string;
  movesNormalizedCount(): number;
  movesCount(): number;
  moves(): string;
}

export { SolveResult, KlondikeSolver };
