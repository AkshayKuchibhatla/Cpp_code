enum Stage {
    EMPTY=7,
    HEAD=14,
    BODY=21,
    ONE_ARM=28,
    BOTH_ARMS=35,
    ONE_LEG=42,
    BOTH_LEGS=49
};
const string words[225] = {
    "surface","excellent","arrangement","year","paragraph","my","herd","too","construction","friendly","wonderful","deeply","account","pure","combine"
    "consonant","quick","chemical","dust","fed","dirty","because","weigh","airplane","enemy","applied","pride","even","steady","disease"
    "surprise","education","growth","year","worse","bone","home","course","porch","mud","coming","gentle","carbon","making","handsome"
    "known","silly","able","score","most","pile","safe","very","body","spin","round","planned","sugar","bend","combine"
    "read","dozen","win","shore","act","pull","notice","throughout","pictured","guard","enter","such","language","ranch","fresh"
    "stranger","invented","summer","without","example","bat","right","tin","almost","disease","trick","stick","sit","soap","football"
    "building","cast","buried","important","send","hurry","sudden","become","here","throat","attention","theory","forgot","bill","known"
    "gave","freedom","dance","courage","boat","lie","office","noun","shoe","twice","luck","kids","effect","strange","develop"
    "carbon","women","hunt","leather","piece","religious","desk","station","soft","biggest","sent","pair","chemical","seven","over"
    "well","double","tent","grade","applied","review","hidden","recall","small","brass","should","broken","perfectly","corn","bank"
    "hold","spite","birthday","composition","television","upon","degree","yard","course","type","additional","least","expression","refused","twice"
    "brave","degree","go","trunk","though","grabbed","open","come","paper","plane","shelter","will","party","require","slave"
    "acres","why","shape","think","roof","everybody","tiny","high","product","sign","sunlight","heavy","choose","shelter","coach"
    "luck","sense","look","teach","society","drove","seldom","been","anybody","bow","let","victory","manner","top","line"
    "immediately","screen","exactly","ran","typical","brave","softly","range","luck","solar","vegetable","whom","darkness","sense","coffee"
    "clothing","fact","equator","green","airplane","hungry","eleven","view","carbon","drop","health","concerned","doing","careful","shut"
};

struct Hangman {
    Stage stage;
    std::string word;

    // Constructor
    Hangman();

    void render();
    void setStage(Stage stage);
};