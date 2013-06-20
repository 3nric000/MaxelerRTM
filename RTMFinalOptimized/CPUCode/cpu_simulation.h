// Stencil
void construct_stencil();
// Propagation
void prop_source(int);
// Take time derivative of data and mute out direct arrival
void differentiate_mute_data(char *);
// Migrate a single shot
void migrate_shot();
max_file_t *maxfile;
max_engine_t *engine;
max_actions_t* act;
void setup_dfe();

