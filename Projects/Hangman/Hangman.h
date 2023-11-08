enum Stage {
    EMPTY=7,
    HEAD=14,
    BODY=21,
    ONE_ARM=28,
    BOTH_ARMS=35,
    ONE_LEG=42,
    BOTH_LEGS=49
};

const std::string words[240] = {
    "might","aside","once","breathing","stood","atom","game","us","powerful","view","name","unit","remove","long","hill",
    "moment","hang","dropped","knife","lack","week","composition","situation","temperature","off","including","unless","engineer","explain","belong",
    "barn","capital","met","trunk","blanket","massage","hardly","nearer","activity","feel","exchange","ants","cast","explain","contain",
    "coach","ate","vessels","spell","surrounded","village","produce","characteristic","later","signal","wish","driving","never","am","cloud",
    "slip","cream","factor","board","group","die","selection","fruit","pool","village","rise","shake","flat","support","negative",
    "onto","built","gave","field","understanding","perfect","north","curve","declared","join","park","thank","herd","source","feel",
    "gate","adult","dropped","out","measure","type","vapor","comfortable","grass","snow","went","then","buy","valley","success",
    "correctly","sink","pitch","up","load","cry","negative","voyage","clothes","send","home","shade","handsome","aware","ever",
    "fewer","vast","angry","atomic","leave","community","scientific","put","mistake","recognize","huge","today","discuss","bit","introduced",
    "brown","live","average","he","electricity","serious","crop","fair","sugar","fair","distant","written","harbor","heat","modern",
    "stick","pie","dried","simply","owner","dawn","together","nervous","tired","vowel","at","finger","alike","raise","sun",
    "naturally","angle","post","tomorrow","church","those","no","zero","motion","ourselves","proper","case","crop","cookies","die",
    "mirror","castle","bottle","black","expect","bill","keep","scene","fuel","instrument","everywhere","problem","route","whistle","form",
    "prevent","forget","atomic","brain","save","black","nothing","yes","tiny","red","expect","few","earth","pond","sale",
    "anyway","ever","throughout","trick","mind","spent","arrangement","them","moment","darkness","nuts","highest","police","industry","made",
    "amount","harder","edge","fewer","glad","depend","realize","successful","some","face","lunch","dot","vessels","due","hope"
};

struct Hangman {
    Stage stage;
    std::string word;
    std::string userGuess;

    // Constructor
    Hangman();

    // Modifiers
    void render();
    void setStage(Stage stage);
    void nextStage();
    void replaceLetters(char letter);

    // Pure function
    bool hasLetter(char letter);
};