using System.IO;

namespace Puma
{
    [Sharpmake.Generate]
    public class TimeSolution : Puma.Common.IMySolution
    {
        public TimeSolution()
            : base("Time")
        {}

        public override void ConfigureAll(Configuration conf, Sharpmake.Target target)
        {
            base.ConfigureAll(conf, target);

            conf.AddProject<Puma.Time>( target );
            conf.AddProject<Puma.TimeTests>( target );
        }
    }
}